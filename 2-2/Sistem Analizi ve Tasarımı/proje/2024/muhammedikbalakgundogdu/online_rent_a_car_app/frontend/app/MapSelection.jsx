import React, { useState } from 'react';
import { View, TouchableOpacity, Text, StyleSheet, Alert } from 'react-native';
import MapView, { Marker } from 'react-native-maps';
import { router } from 'expo-router';
import AsyncStorage from '@react-native-async-storage/async-storage';


const getMarkerFromStorage = async () => {
  try {
    const marker = await AsyncStorage.getItem('marker');
    if (marker !== null) {
      console.log('Marker:', JSON.parse(marker));
      return JSON.parse(marker);
    } else {
      console.log('Marker bulunamadı.');
      return null;
    }
  } catch (error) {
    console.error('Hata:', error);
    return null;
  }
};

const getMarker1FromStorage = async () => {
  try {
    const marker = await AsyncStorage.getItem('phoneNumber');
    if (marker !== null) {
      console.log('phoneNumber:', JSON.parse(marker));
      return JSON.parse(marker);
    } else {
      console.log('Marker bulunamadı.');
      return null;
    }
  } catch (error) {
    console.error('Hata:', error);
    return null;
  }
};

const MapSelection = () => {
  const [selectedCoordinate, setSelectedCoordinate] = useState(null);
  
  
  const handleMapPress = (event) => {
    setSelectedCoordinate(event.nativeEvent.coordinate);
  };

  
  const handleConfirmSelection = async () => {
    if (selectedCoordinate) {
      if (isInsideIstanbul(selectedCoordinate)) {
        const storedMarker = await getMarkerFromStorage();
        if (storedMarker) {
          storedMarker.x = selectedCoordinate.longitude;
          storedMarker.y = selectedCoordinate.latitude;  
          try {
            const telNumber = await getMarker1FromStorage();
            const response1 = await fetch(`http://192.168.159.138:8080/api/userInfo/${telNumber}`);
            const responseData1 = await response1.json();
            
            const response = await fetch(`http://192.168.159.138:8080/admin/updateCarPayment/${responseData1.data.userId}`, {
                method: 'PUT',
                headers: {
                  'Content-Type': 'application/json; charset=UTF-8',
                },
                body: JSON.stringify({
                  type: storedMarker.type,
                  carKilometer: storedMarker.carKilometer,
                  x: parseFloat(selectedCoordinate.longitude),
                  y: parseFloat(selectedCoordinate.latitude),
                  amountOfFuel: storedMarker.amountOfFuel,
                  isRented: false,
                }),
              });
            const responseData = await response.json();
            console.log(responseData.isSuccess)
            if (response.ok && responseData.isSuccess) {
              Alert.alert('Success', responseData.message);
            } else {
              Alert.alert('Error', responseData.message);
            }
            /*try {
      const response = await fetch('http://192.168.159.138/admin/saveCar', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          carKilometer: carAdd.car_kilometer,
          lastServiceDateMonth: carAdd.car_last_service,
          carPrice: carAdd.car_price,
          statue: carAdd.car_statue,
          type: carAdd.car_type,
        }),
      });
      const data = await response.json();
      if (response.ok) {
        Alert.alert('Success', data.message);
      } else {
        Alert.alert('Error', data.message);
      }
    }*/
           router.push("/home");
            // Handle success or error response
          } catch (error) {
            console.error('Error updating car:', error);
            // Handle error
          }
          //burada databaseye yeni car nesnesini yollayacagım
        } else {
          console.log("Kayıtlı marker bulunamadı.");
        }
      } else {
        alert("Seçilen yer İstanbul sınırları içinde değil.");
      }
    }
  };
  

  const isInsideIstanbul = (coordinate) => {
    // İstanbul sınırlarını belirleyen koordinat aralığı
    const istanbulBounds = {
      north: 41.2354,
      south: 40.8027,
      east: 29.3594,
      west: 28.6470,
    };
    // Koordinat, İstanbul sınırları içinde mi kontrol edilir
    return (
      coordinate.latitude >= istanbulBounds.south &&
      coordinate.latitude <= istanbulBounds.north &&
      coordinate.longitude >= istanbulBounds.west &&
      coordinate.longitude <= istanbulBounds.east
    );
  };

  return (
    <View style={styles.container}>
      <MapView
        initialRegion={{
          latitude: 41.0286,
          longitude: 28.8760,
          latitudeDelta: 0.1,
          longitudeDelta: 0.1,
        }}
        style={styles.map}
        onPress={handleMapPress}
      >
        {selectedCoordinate && (
          <Marker
            coordinate={selectedCoordinate}
            pinColor="blue"
          />
        )}
      </MapView>
      <TouchableOpacity style={styles.button} onPress={handleConfirmSelection}>
        <Text style={styles.buttonText}>Confirm Selection</Text>
      </TouchableOpacity>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  map: {
    flex: 1,
  },
  button: {
    position: 'absolute',
    bottom: 20,
    alignSelf: 'center',
    backgroundColor: 'blue',
    paddingVertical: 10,
    paddingHorizontal: 20,
    borderRadius: 5,
  },
  buttonText: {
    color: 'white',
    fontSize: 16,
    fontWeight: 'bold',
  },
});

export default MapSelection;
