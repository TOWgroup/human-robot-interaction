## Dependencies

```
pip install -r requirements.txt
```

## Training

**Set cuda usage**

```
!export CUDA_VISIBLE_DEVICES=5
```

then add the device="cuda:5" to args
<br/>

```python
!python modules/main.py --do_train --augment --config yaml/config_train.yaml
```

## Inference

1. Evaluate and tune thresholds

```python
!python modules/main.py --do_infer --eval --config yaml/config_eval.yaml
```

2. Run on Test set

```python
!python modules/main.py --do_infer --test --config yaml/config_test.yaml
```

## Citation

[1] _In defence of metric learning for speaker recognition_

```
@inproceedings{chung2020in,
    title={In defence of metric learning for speaker recognition},
    author={Chung, Joon Son and Huh, Jaesung and Mun, Seongkyu and Lee, Minjae and Heo, Hee Soo and Choe, Soyeon and Ham, Chiheon and Jung, Sunghwan and Lee, Bong-Jin and Han, Icksang},
    booktitle={Interspeech},
    year={2020}
}
```

[2] _Clova baseline system for the VoxCeleb Speaker Recognition Challenge 2020_

```
@article{heo2020clova,
    title={Clova baseline system for the {VoxCeleb} Speaker Recognition Challenge 2020},
    author={Heo, Hee Soo and Lee, Bong-Jin and Huh, Jaesung and Chung, Joon Son},
    journal={arXiv preprint arXiv:2009.14153},
    year={2020}
}
```

[3] _Analysis of score normalization in multilingual speaker recognition_

```
@inproceedings{inproceedings,
    title = {Analysis of Score Normalization in Multilingual Speaker Recognition},
    author = {Matejka, Pavel and Novotny, Ondrej and Plchot, Oldřich and Burget, Lukas and Diez, Mireia and Černocký, Jan},
    booktitle = {Interspeech},
    year = {2017}
}
```
