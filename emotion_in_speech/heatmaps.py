import numpy as np
from sklearn.decomposition import PCA
import sys
import csv
import seaborn as sns
from sklearn.cross_decomposition import PLSRegression
import pandas
import matplotlib
import os
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import label_binarize
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import pdb; pdb.set_trace()
from matplotlib import pyplot as plt
from matplotlib import cm as cm


# this function creates heatmaps for correalation of features
# it also creates a histogram based on the frame number of each sound file

class Heatmap:
    def __init__(self, path_to_features, path_to_labels, name):
        self.name = name
        x, y, row_shapes = self.get_features(path_to_features, path_to_labels)
        self.row_shapes = row_shapes
        scaler = StandardScaler()
        x = scaler.fit_transform(x)
        df_ = pandas.DataFrame(x)
        df = df_.corr()
        self.df = pandas.DataFrame(df.values)

    def load_x(self, name):
        df = pandas.read_csv(name, sep=',', index_col=None)
        row_shape = df.shape[0]
        x = np.mean(df, axis=0)
        return np.array(x, dtype=float), row_shape

    def load_x_opensmile(self, name):
        df = pandas.read_csv(name, sep=';', index_col=None)
        df = df.iloc[:, 3:]
        row_shape = df.shape[0]
        x = np.mean(df, axis=0)
        return np.array(x, dtype=float), row_shape

    def load_y(self, name):
        df = pandas.read_csv(name, sep=',', index_col=None)
        y = np.array(df.values)
        return y

    def get_features(self, path_x, path_y):
        files = os.listdir(path_x)
        tx = []
        ty = []
        row_shapes = []
        a = len(files)
        k = 1
        for f in files:
            if k % 500 == 0:
                print str(k) + " out of " + str(a)
                return tx, ty, row_shapes
            k += 1
            if self.name != "opensmile":
                x, row_shape = self.load_x(path_x + '/' + f)
            else:
                x, row_shape = self.load_x_opensmile(path_x + '/' + f)
            y = self.load_y(path_y + f)
            if len(x) > 0:
                tx.append(np.array(x, dtype=float))
                ty.append(y[0])
                row_shapes.append(row_shape)
        tx = np.array(tx)
        ty = np.array(ty)
        return tx, ty, row_shapes

    def create_heat_map(self, folder):
            ax = sns.heatmap(self.df).set_title('Heatmap correlation of the features')
            plt.savefig(folder + "correlation_of_features.png")
            plt.close()
            n, bins, patches = plt.hist(self.row_shapes, 50,
                                        facecolor='g', alpha=0.75)
            plt.xlabel('row_shapes')
            plt.ylabel('amount')
            plt.title('Histogram of row_shapes')
            plt.grid(True)
            plt.savefig(folder + "Histogram_of_row_shapes.png")
            plt.close()
