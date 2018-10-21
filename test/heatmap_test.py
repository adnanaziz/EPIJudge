import sys
sys.path.append('../')
import feature_selection.heatmaps as H

path_to_features1 = "/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/nsynth_features/"

path_to_features2 = '/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/pyaudio_more_cat/'

path_to_features3 = '/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/mel/'

path_to_features4 = '/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/pyaudio_less_cat/'

path_to_labels = '/nas/lrz/tuei/ldv/studierende/' + \
                 'Emotion/IEMOCAP_full_release/IEMOCAP_labels_regression/'

path_to_features5 = "/nas/lrz/tuei/ldv/studierende/Emotion/IEMOCAP_full_release/same_length/opensmile/"

path_list = [path_to_features1, path_to_features2, path_to_features3,
             path_to_features4, path_to_features5]

folder = "plot/"

name = ['nsynth', 'pyAudio',
        'mel_band', 'pyAudio', 'opensmile']
for i in xrange(5):
    heat = H.Heatmap(path_list[i], path_to_labels, name[i])
    heat.create_heat_map(folder)
