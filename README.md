# Emotion Recognition in Speech

## Introduction

Emotion Recognition from Speech evaluates IEMOCAP dataset

- With different **feature extraction tools** such as pyaudioAnalysis, librosa, opensmile and nsynth autoencoder by magenta

- With **Feature Selection** by using mutual information, F-test, p-values, PLS-DA, PLS-R, PCA, 2D-PCA, standart deviation and correlation

- With **Classical machine Learning Tools** such as GMM, SVM and SVR

- With **Neural Networks**, with Timedistributed, LSTM, Bi-LSTM, CNN-LSTM

- **Parameter Search:** Gridsearch for SVM, SVR and GMM. Hyperas for neural networks

- Each step is evaluated using cross-validation

## Installation

You can download this project $ git clone "project_name"

## Requirements

- hyperas, hyperopt, keras, tensorflow, librosa, numpy, pandas, scikit-learn, seaborn, scipy, sklearn, tensorflow, matplotlib, nsynth (for nsynth you need python3) 