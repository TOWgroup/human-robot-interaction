import torch


def adam(parameters, lr=0.001, weight_decay=0.95, **kwargs):
    # print('Initialised Adam optimizer')
    return torch.optim.Adam(parameters,
                            lr=float(lr),
                            weight_decay=float(weight_decay))
