Build based on audio_common packages of ROS <br/>

we add some things below to perform our task:

- audio_common_mgs/msg/AudioData: change UInt16 -> Int16
- audio_common/audio_capture/src: add audio_capture_py.py node to perform getting audio signal from stream line and publish it into AudioData topic
- some other nodes in audio_play/src

Add speakerVerification_pkg package to perform speaker verification task, <br/>
To run:

```
roscore
```

```
rosrun audio_capture audio_capture_py.py
```

```
rosrun SpeakerVerification_pkg ros_node_verification.py
```
