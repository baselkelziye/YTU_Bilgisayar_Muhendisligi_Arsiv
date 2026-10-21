import pandas as pd
import numpy as np
import os
import json
import torchvision as tv
import torch
from PIL import Image
from torch.utils.data import DataLoader, random_split, Dataset
import matplotlib.pyplot as plt
import torch.nn as nn
import torch.nn.functional as F
import cv2
from torchsummary import summary
import math
import ast

class EncoderBlock(nn.Module):
    
    def __init__(
        self, in_channels, out_channels, batchnorm=True, activation_fn=nn.ReLU
    ):
        super().__init__()
        
        layers = []
        
        self.batchnorm=batchnorm
        
        self.conv = nn.Conv2d(
            in_channels=in_channels,
            out_channels=out_channels,
            padding=(1, 1), 
            padding_mode='zeros', 
            kernel_size=(4, 4), 
            stride=(2, 2)
        )

        self.activation = activation_fn()
        
        if self.batchnorm:
            self.batchnorm = nn.BatchNorm2d(
                num_features=out_channels
            )
        
        
    def forward(self, x):
        
        x = self.conv(x)
        x = self.activation(x)

        if self.batchnorm:
            x = self.batchnorm(x)
        
        return x
    

class DecoderBlock(nn.Module):
    
    def __init__(self, in_channels, out_channels, activation_fn=nn.ReLU):
        super().__init__()
        
        self.upconv = nn.ConvTranspose2d(
            in_channels=in_channels, 
            out_channels=out_channels, 
            padding=(1, 1), 
            padding_mode='zeros', 
            kernel_size=(4, 4), 
            stride=(2, 2)
        )
        
        
        self.activation = activation_fn()

        self.batchnorm = nn.BatchNorm2d(
            num_features=out_channels
        )
        
        
    def forward(self, x, skip_in):
        
        x = self.upconv(x)
        
        x = x + skip_in
        x = self.activation(x)
        
        x = self.batchnorm(x)
        
        return x
    


class LinkNet(nn.Module):
    
    def __init__(self):
        super().__init__()
        
        # (3, 256, 256) -> (32, 128, 128)
        self.e1 = EncoderBlock(in_channels=3, 
            out_channels=32
        )
        
        # (32, 128, 128) -> (64, 64, 64)
        self.e2 = EncoderBlock(
            in_channels=32, 
            out_channels=64
        )
        
        # (64, 64, 64) -> (128, 32, 32)
        self.e3 = EncoderBlock(
            in_channels=64, 
            out_channels=128
        )
        
        # (128, 32, 32) -> (256, 16, 16)
        self.e4 = EncoderBlock(
            in_channels=128, 
            out_channels=256
        )

        self.e5 = EncoderBlock(
            in_channels=256,
            out_channels=512
        )
        
        # bottleneck (512, 8, 8) -> (512, 4, 4)
        self.b = nn.Conv2d(
            in_channels=512,
            out_channels=512,
            padding=(1, 1), 
            padding_mode='zeros', 
            kernel_size=(4, 4), 
            stride=(2, 2)
        )
        
        # (512, 4, 4) -> (512, 8, 8)
        self.d1 = DecoderBlock(
            in_channels=512, 
            out_channels=512
        )
        
        # (512, 8, 8) -> (256, 16, 16)
        self.d2 = DecoderBlock(
            in_channels=512, 
            out_channels=256
        )
        
        # (256, 16, 16) -> (128, 32, 32)
        self.d3 = DecoderBlock(
            in_channels=256, 
            out_channels=128
        )
        
        # (128, 32, 32) -> (64, 64, 64)
        self.d4 = DecoderBlock(
            in_channels=128, 
            out_channels=64
        )
        
        # (64, 64, 64) -> (32, 128, 128)
             
        self.d5 = DecoderBlock(
            in_channels=64, 
            out_channels=32
        )
        
        # output (32, 128, 128) -> (1, 256, 256)
        self.o = nn.ConvTranspose2d(
            in_channels=32, 
            out_channels=1, 
            padding=(1, 1), 
            padding_mode='zeros', 
            kernel_size=(4, 4), 
            stride=(2, 2)
        )
        
    def forward(self, x):
        
        e1 = self.e1(x)
        e2 = self.e2(e1)
        e3 = self.e3(e2)
        e4 = self.e4(e3)
        e5 = self.e5(e4)
        
        b = self.b(e5)
        b = F.relu(b)
        
        d1 = self.d1(b, e5)
        d2 = self.d2(d1, e4)
        d3 = self.d3(d2, e3)
        d4 = self.d4(d3, e2)
        d5 = self.d5(d4, e1)
        
        output = self.o(d5)
        output = torch.sigmoid(output)

        return output