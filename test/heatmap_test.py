import sys
sys.path.append('../')
import feature_selection.heatmaps as H

path_to_labels = '/nas/lrz/tuei/ldv/studierende/' + \
                 'Emotion/IEMOCAP_full_release/IEMOCAP_labels_regression/'

path_to_features = "/home/ga25gux/tensorflow_python2/EPIJudge/example_dataset/"

folder = "plot/"

name = 'nsynth'


heat = H.Heatmap(path_to_features, path_to_labels, name)
heat.create_heat_map(folder)
