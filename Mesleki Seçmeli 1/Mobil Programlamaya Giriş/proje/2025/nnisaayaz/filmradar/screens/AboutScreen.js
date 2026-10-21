import React from 'react';
import { View, Text, StyleSheet, ScrollView } from 'react-native';
import { Ionicons } from '@expo/vector-icons';

export default function AboutScreen() {
  return (
    <ScrollView contentContainerStyle={styles.scroll}>
      <View style={styles.card}>
        <Ionicons name="film-outline" size={60} color="#1976d2" style={{ marginBottom: 10 }} />
        <Text style={styles.title}>FilmRadar</Text>
        <Text style={styles.desc}>
          Popüler filmleri keşfet, favorilerine ekle. Tüm sinefiller için sevgi ile yapıldı. 
        </Text>
        <Text style={styles.sectionTitle}>Kim Yaptı</Text>
        <Text style={styles.author}>Nisa Ayaz</Text>
        <Text style={styles.smallDesc}>
          Tam adım Nisanur Ayaz ancak Nisa'yı kullanıyorum. Fenerbahçeliyim. Boğa burcuyum.
        </Text>
        <Text style={styles.sectionTitle}>Özel Teşekkürler</Text>
        <View style={styles.thankList}>
          <Text style={styles.thankItem}>Annem — Odaya yemek servisiyle aç bırakmadığı için.</Text>
          <Text style={styles.thankItem}>Kardeşim — Minimum seviyede rahatsız ettiği için.</Text>
          <Text style={styles.thankItem}>Babam — The Financial Resource. Can't thank him enough.</Text>
        </View>
        <Text style={styles.sectionTitle}>Ne kullandım</Text>
        <Text style={styles.tech}>
          - React Native (Expo){'\n'}
          - TMDB Open API{'\n'}
          - Doğaçlama ve içgüdü
        </Text>
        <Text style={styles.version}>v1.0.0 - 2025</Text>
      </View>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  scroll: { flexGrow: 1, justifyContent: 'center', alignItems: 'center', backgroundColor: '#f3f6fa', padding: 20 },
  card: {
    width: '100%',
    backgroundColor: '#fff',
    borderRadius: 24,
    padding: 26,
    alignItems: 'center',
    shadowColor: '#000',
    shadowOpacity: 0.06,
    shadowRadius: 8,
    elevation: 3,
  },
  title: { fontSize: 27, fontWeight: 'bold', color: '#1976d2', marginBottom: 8 },
  desc: { fontSize: 17, textAlign: 'center', marginBottom: 18, color: '#222' },
  sectionTitle: { marginTop: 14, fontWeight: '700', fontSize: 16, color: '#1976d2', alignSelf: 'flex-start', marginBottom: 2 },
  author: { fontSize: 18, fontWeight: 'bold', color: '#222', marginBottom: 4, alignSelf: 'flex-start' },
  smallDesc: { fontSize: 15, color: '#444', marginBottom: 12, alignSelf: 'flex-start' },
  thankList: { width: '100%', marginBottom: 8, marginTop: 6 },
  thankItem: { fontSize: 15, color: '#222', marginVertical: 1.5 },
  tech: { fontSize: 15, color: '#222', marginTop: 8, marginBottom: 6, alignSelf: 'flex-start' },
  version: { color: '#888', fontSize: 13, marginTop: 14, alignSelf: 'flex-end' },
});
