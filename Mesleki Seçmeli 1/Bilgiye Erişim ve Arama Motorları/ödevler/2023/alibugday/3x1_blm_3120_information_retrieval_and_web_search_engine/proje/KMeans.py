import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import Pipeline
from sklearn.metrics.pairwise import euclidean_distances
from collections import defaultdict

class Kmeans():
    def __init__(self, data_dosyasi):
        self.dataset = pd.read_csv(data_dosyasi)

        # print(data.head()['id'])

        # print(data.info())

        # print(data[data['name']=="Chapter 1.18 - Zamek kaniowski"]["id"])

        # print(data[data["id"]=="4SCnCPOUOUXUmCX2uHb3r7"])

        self.features = ['valence', 'year', 'acousticness',
                    'danceability', 'duration_ms', 'energy',
                    'explicit', 'instrumentalness', 'key',
                    'liveness', 'loudness', 'mode',
                    'popularity', 'speechiness', 'tempo']

        self.metadata_cols = ['year', 'name', 'artists']

        self.song_cluster_pipeline = Pipeline([('scaler', StandardScaler()),
                                          ('kmeans', KMeans(n_clusters=8,
                                                            verbose=2))], verbose=True)
        self.X = self.dataset[self.features]
        self.song_cluster_pipeline.fit(self.X)


    def input_preprocessor(self, song_list):
        song_vectors = []

        for song in song_list:
            try:
                song_data = self.dataset[(self.dataset['name'] == song['name']) &
                                    (self.dataset['year'] == song['year'])].iloc[0]

            except IndexError:
                song_data = None

            if song_data is None:
                print('Warning: {} does not exist in our database'.format(song['name']))
                continue

            song_vectors.append(song_data[self.features].values)

        return np.mean(np.array(list(song_vectors)), axis=0)


    def Music_Recommender(self, song_list, n_songs=10):
        #groupby_input_tracks = tracks_groupby(song_list)
        song_center = self.input_preprocessor(song_list)

        scaler = self.song_cluster_pipeline.steps[0][1]
        scaled_data = scaler.transform(self.dataset[self.features])
        scaled_song_center = scaler.transform(song_center.reshape(1, -1))

        ed_dist = euclidean_distances(scaled_song_center, scaled_data)

        index = list(np.argsort(ed_dist)[:, :n_songs][0])
        rec_output = self.dataset.iloc[index]

        return rec_output[self.metadata_cols]



if __name__=='__main__':
    obje=Kmeans("data.csv")

    results = obje.Music_Recommender([{'name': 'Toosie Slide', 'year': 2020},
                                {'name': 'Outta Time (feat. Drake)', 'year': 2020},
                                {'name': 'Chicago Freestyle (feat. Giveon)', 'year': 2020}])
    print(results)