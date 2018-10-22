import sys
import os
sys.path.append('../')
import emotion_in_speech.heatmaps as H

path = os.path.abspath(__file__)

path = os.path.abspath(os.path.join(path, os.pardir))

parentDir = os.path.abspath(os.path.join(path, os.pardir))

path_to_labels = os.path.abspath(os.path.join(parentDir,
                                              "example_labels_classification"))
path_to_labels = path_to_labels + '/'
path_to_features = os.path.abspath(os.path.join(parentDir, "example_dataset/"))
path_to_features = path_to_features + '/'

folder = "plot/"

name = 'nsynth'


heat = H.Heatmap(path_to_features, path_to_labels, name)
heat.create_heat_map(folder)
