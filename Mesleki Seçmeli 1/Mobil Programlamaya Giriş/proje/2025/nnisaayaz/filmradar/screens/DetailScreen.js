import React from 'react';
import { View, Text, Image, StyleSheet, ScrollView } from 'react-native';
import { Ionicons } from '@expo/vector-icons';

const IMAGE_URL = 'https://image.tmdb.org/t/p/w500';

export default function DetailScreen({ route }) {
  const { movie } = route.params;

  return (
    <ScrollView contentContainerStyle={styles.scroll}>
      <View style={styles.card}>
        <Image source={{ uri: IMAGE_URL + movie.poster_path }} style={styles.poster} />
        <Text style={styles.title}>{movie.title}</Text>
        <View style={styles.metaRow}>
          <View style={styles.badge}>
            <Ionicons name="calendar" size={16} color="#1976d2" />
            <Text style={styles.badgeText}>{movie.release_date?.split('-')[0]}</Text>
          </View>
          <View style={[styles.badge, { marginLeft: 8 }]}>
            <Ionicons name="star" size={16} color="#FFD700" />
            <Text style={styles.badgeText}>{movie.vote_average?.toFixed(1)}</Text>
          </View>
        </View>
        <Text style={styles.sectionTitle}>Açıklama</Text>
        <Text style={styles.overview}>{movie.overview || "Bu film hakkında açıklama bulunamadı."}</Text>
      </View>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  scroll: {
    alignItems: 'center',
    paddingVertical: 32,
    paddingHorizontal: 18,
    backgroundColor: '#fafcff',
  },
  card: {
    width: '100%',
    backgroundColor: '#fff',
    borderRadius: 22,
    shadowColor: '#000',
    shadowOpacity: 0.06,
    shadowRadius: 10,
    elevation: 3,
    alignItems: 'center',
    paddingBottom: 24,
    paddingTop: 18,
    paddingHorizontal: 8,
  },
  poster: {
    width: 220,
    height: 320,
    borderRadius: 18,
    marginBottom: 18,
    backgroundColor: '#eee',
  },
  title: {
    fontSize: 23,
    fontWeight: 'bold',
    textAlign: 'center',
    marginBottom: 10,
    color: '#222',
  },
  metaRow: {
    flexDirection: 'row',
    alignItems: 'center',
    marginBottom: 10,
    marginTop: -2,
  },
  badge: {
    flexDirection: 'row',
    alignItems: 'center',
    backgroundColor: '#e3f2fd',
    borderRadius: 12,
    paddingHorizontal: 10,
    paddingVertical: 5,
  },
  badgeText: {
    color: '#1976d2',
    fontWeight: 'bold',
    marginLeft: 5,
    fontSize: 15,
  },
  sectionTitle: {
    marginTop: 16,
    fontWeight: '600',
    fontSize: 17,
    color: '#1976d2',
    alignSelf: 'flex-start',
    marginBottom: 5,
    marginLeft: 12,
  },
  overview: {
    fontSize: 16,
    color: '#222',
    textAlign: 'left',
    paddingHorizontal: 12,
    lineHeight: 22,
    marginBottom: 10,
    alignSelf: 'stretch',
  },
});
