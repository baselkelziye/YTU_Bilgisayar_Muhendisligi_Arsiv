import React from 'react';
import { View, Text, Image, TouchableOpacity, StyleSheet } from 'react-native';
import { Ionicons } from '@expo/vector-icons';

const IMAGE_URL = 'https://image.tmdb.org/t/p/w500';

export default function MovieCard({ movie, onPress, isFavorite, onFavorite }) {
  return (
    <TouchableOpacity style={styles.card} onPress={onPress} activeOpacity={0.9}>
      <Image source={{ uri: IMAGE_URL + movie.poster_path }} style={styles.poster} />
      <View style={{ flex: 1, marginLeft: 12 }}>
        <Text style={styles.title} numberOfLines={2}>{movie.title}</Text>
        <Text style={styles.year}>{movie.release_date?.split('-')[0]}</Text>
        <View style={{ flexDirection: 'row', alignItems: 'center', marginTop: 8 }}>
          <Ionicons name="star" size={16} color="#FFD700" />
          <Text style={styles.rating}>{movie.vote_average?.toFixed(1)}</Text>
          <TouchableOpacity onPress={onFavorite} style={{ marginLeft: 'auto', padding: 8 }}>
            <Ionicons
              name={isFavorite ? 'heart' : 'heart-outline'}
              size={22}
              color={isFavorite ? 'red' : 'gray'}
            />
          </TouchableOpacity>
        </View>
      </View>
    </TouchableOpacity>
  );
}

const styles = StyleSheet.create({
  card: {
    flexDirection: 'row',
    backgroundColor: '#fff',
    borderRadius: 18,
    marginVertical: 10,
    marginHorizontal: 16,
    elevation: 3,
    shadowColor: '#000',
    shadowOpacity: 0.09,
    shadowRadius: 8,
    shadowOffset: { width: 0, height: 4 },
    alignItems: 'center',
    padding: 10,
  },
  poster: {
    width: 90,
    height: 135,
    borderRadius: 12,
    backgroundColor: '#eee',
  },
  title: {
    fontSize: 17,
    fontWeight: 'bold',
    color: '#222',
    marginBottom: 3,
  },
  year: {
    color: '#888',
    fontSize: 14,
    marginBottom: 2,
  },
  rating: {
    marginLeft: 5,
    color: '#222',
    fontWeight: '600',
    fontSize: 14,
  },
});
