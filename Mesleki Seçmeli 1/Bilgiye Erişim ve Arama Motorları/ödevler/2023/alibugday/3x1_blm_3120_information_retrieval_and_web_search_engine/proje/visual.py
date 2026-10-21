import pandas as pd
from sklearn.metrics.pairwise import sigmoid_kernel
from sklearn.metrics.pairwise import cosine_similarity
from sklearn import preprocessing
from sklearn.preprocessing import MinMaxScaler


class Cosine_simliarity():
    def __init__(self):
        self.dataset=pd.read_csv("data.csv")

        self.dataset = self.dataset.head(20000)

        self.df=self.dataset.sort_values(by=['popularity'], ascending=False).head(20)


        self.feature_cols=['acousticness', 'danceability', 'duration_ms', 'energy',
                  'instrumentalness', 'key', 'liveness', 'loudness', 'mode',
                  'speechiness', 'tempo', 'valence',]


        self.scaler = MinMaxScaler()
        self.normalized_df =self.scaler.fit_transform(self.dataset[self.feature_cols])

        print(self.normalized_df[:2])

        # Create a pandas series with song titles as indices and indices as series values
        self.indices = pd.Series(self.dataset.index, index=self.dataset['name']).drop_duplicates()


        # Create cosine similarity matrix based on given matrix
        self.cosine = cosine_similarity(self.normalized_df)

    def generate_recommendation(self,song_title):
        """
        Purpose: Function for song recommendations
        Inputs: song title and type of similarity model
        Output: Pandas series of recommended songs
        """
        # Get song indices
        index=self.indices[song_title]
        # Get list of songs for given songs
        score=list(enumerate(self.cosine[self.indices[song_title]]))
        # Sort the most similar songs
        similarity_score = sorted(score,key = lambda x:x[1],reverse = True)
        # Select the top-10 recommend songs
        similarity_score = similarity_score[1:11]
        top_songs_index = [i[0] for i in similarity_score]
        # Top 10 recommende songs
        top_songs=self.dataset['name'].iloc[top_songs_index]
        return top_songs

#print(df.head(20)["name"])


if __name__=='__main__':
    print("Recommended Songs:")
    obje = Cosine_simliarity()

    print(obje.generate_recommendation('Forever Yours - Avicii Tribute').values)