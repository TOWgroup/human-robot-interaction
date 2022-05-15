#!/usr/bin/env python3

import argparse
import glob
import json
import os
import time
from calendar import c
from pathlib import Path
from tabnanny import check

import numpy as np
import rospy
from audio_common_msgs.msg import AudioData, AudioInfo
from tqdm.auto import tqdm

from model import SpeakerNet
from processing.audio_loader import loadWAV
from server_utils import *
from utils import cprint, read_config, similarity_measure

# ======================Load model===========================
sr = 16000
eval_frames = 100
num_eval = 10
normalize = True

threshold = 0.4901626706123352

model_path = str(Path('src/SpeakerVerification_pkg/src/backup/tow/Raw_ECAPA/model/best_state_eer177e-2.model'))
config_path = str(Path('src/SpeakerVerification_pkg/src/backup/tow/Raw_ECAPA/config_eval.yaml'))
print("\n<<>> Loaded from:", model_path, "with threshold:", threshold)

# read config and load model
args = read_config(config_path)

t0 = time.time()
model = SpeakerNet(**vars(args))
model.loadParameters(model_path, show_error=False)
model.eval()
print("Model Loaded time: ", time.time() - t0)

# ======================Ros node===========================
coms = ['src/Recorded_audio/dat_tow/3_test_vi_vad_0.wav',
        'src/Recorded_audio/loc_tow/3_test_vi_vad_0.wav',
        'src/Recorded_audio/vuong_tow/3_test_vi_vad_1.wav',
        'src/Recorded_audio/nam_tow/Nam.wav']
dts_path = 'src/Recorded_audio/'
emb_path = 'src/Embeddings/'


def check_matching(model, signal_ref, signal_com, key_name):
    ref_emb = model.embed_utterance(signal_ref,
                                    eval_frames=eval_frames,
                                    num_eval=num_eval,
                                    normalize=normalize, sample_rate=sr)

    com_emb = model.embed_utterance(signal_com,
                                    eval_frames=eval_frames,
                                    num_eval=num_eval,
                                    normalize=normalize, sample_rate=sr)
    score = similarity_measure('cosine', torch.FloatTensor(ref_emb), torch.FloatTensor(com_emb))
    print(f"Score {key_name}:", score)


def callback(data):
    data_str = str(data).replace('data:', '').strip()
    data_lst = json.loads(data_str)
    data_np = np.array(data_lst)
    print(f'\n> Received data: {data_np}. Start processing...')
    for com in coms:
        key_name = str(Path(com).parent.name)
        check_matching(model, data_np, com, key_name)


def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("/audio/audio", AudioData, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()


if __name__ == '__main__':
    listener()
