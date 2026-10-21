import React, { useEffect, useState, useContext } from 'react';
import { Text, FlatList, ActivityIndicator, StyleSheet, TextInput, View, TouchableOpacity } from 'react-native';
import axios from 'axios';
import { FavoritesContext } from '../context/FavoritesContext';
import MovieCard from '../components/MovieCard';
import { SafeAreaView } from 'react-native-safe-area-context';

const API_KEY = '66d0df5509daf1ebdc2668eabafad96a';
const API_URL = `https://api.themoviedb.org/3/movie/popular?api_key=${API_KEY}&language=tr-TR&page=1`;

export default function HomeScreen({ navigation }) {
  const [movies, setMovies] = useState([]);
  const [loading, setLoading] = useState(true);
  const [search, setSearch] = useState('');
  const { addFavorite, removeFavorite, isFavorite } = useContext(FavoritesContext);
  const [showFavorites, setShowFavorites] = useState(false);


  useEffect(() => {
    axios.get(API_URL)
      .then((res) => {
        setMovies(res.data.results);
        setLoading(false);
      })
      .catch(() => {
        setLoading(false);
      });
  }, []);

  if (loading) {
    return (
      <SafeAreaView style={styles.center}>
        <ActivityIndicator size="large" color="#666" />
        <Text>Yükleniyor...</Text>
        <TouchableOpacity
  style={styles.tabButton}
  onPress={() => setShowFavorites(!showFavorites)}
>
  <Text style={styles.tabButtonText}>
    {showFavorites ? 'Tüm Filmler' : 'Favorilerim'}
  </Text>
</TouchableOpacity>

      </SafeAreaView>
    );
  }

  return (
    <SafeAreaView style={styles.flex} edges={['bottom']}>
      <View style={styles.container}>
        <TouchableOpacity
  style={styles.tabButton}
  onPress={() => setShowFavorites(!showFavorites)}
>
  <Text style={styles.tabButtonText}>
    {showFavorites ? 'Tüm Filmler' : 'Favorilerim'}
  </Text>
</TouchableOpacity>

        <TextInput
          placeholder="Film ara..."
          value={search}
          onChangeText={setSearch}
          style={styles.input}
        />
        <FlatList
          data={
  (showFavorites
    ? movies.filter(item => isFavorite(item.id))
    : movies
  ).filter(item =>
    item.title.toLowerCase().includes(search.toLowerCase())
  )
}

          keyExtractor={(item) => item.id.toString()}
          renderItem={({ item }) => (
            <MovieCard
              movie={item}
              isFavorite={isFavorite(item.id)}
              onFavorite={() =>
                isFavorite(item.id) ? removeFavorite(item.id) : addFavorite(item)
              }
              onPress={() => navigation.navigate('Detail', { movie: item })}
            />
          )}
          contentContainerStyle={{ paddingBottom: 40, paddingTop: 0 }}
          ListFooterComponent={
  <View style={{ alignItems: 'center', marginTop: 12 }}>
    <TouchableOpacity onPress={() => navigation.navigate('About')}>
      <Text style={styles.footerButtonText}>Hakkında</Text>
    </TouchableOpacity>
    <Text style={styles.footerText}>
      © 2025 Nisa Ayaz - All rights reserved.
    </Text>
  </View>
}

        />
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  flex: { flex: 1, backgroundColor: '#fff' },
  container: { flex: 1, paddingTop: 0 },
  center: { flex: 1, justifyContent: 'center', alignItems: 'center' },
  input: {
    borderWidth: 1, borderColor: '#ccc', borderRadius: 8,
    padding: 8, margin: 10,
  },
  tabButton: {
    backgroundColor: '#000000',
    paddingVertical: 12,
    borderRadius: 10,
    marginHorizontal: 10,
    marginTop: 0,
    marginBottom: 10,
  },
  tabButtonText: {
    color: '#fff',
    textAlign: 'center',
    fontWeight: 'bold',
    letterSpacing: 1,
    fontSize: 17,
  },
  footerText: {
    color: '#aaa',
    fontSize: 12,
    textAlign: 'center',
    marginTop: 18,
    marginBottom: 10,
  },
  footerButtonText: {
  backgroundColor: '#2196f3',
  color: '#fff',
  fontWeight: 'bold',
  paddingHorizontal: 28,
  paddingVertical: 12,
  borderRadius: 10,
  fontSize: 16,
  marginBottom: 6,
},

});
