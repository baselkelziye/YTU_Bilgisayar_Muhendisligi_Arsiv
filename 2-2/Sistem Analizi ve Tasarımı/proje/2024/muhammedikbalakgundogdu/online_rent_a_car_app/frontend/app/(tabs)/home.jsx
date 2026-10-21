import React, { useEffect, useState } from 'react';
import MapView, { Marker } from 'react-native-maps';
import { StyleSheet, View, Image } from 'react-native';
import { icons } from '../../constants'; // constants dosyasından resimleri içe aktarın
import CustomModal from '../../components/ChosonCarModal'; // CustomModal bileşenini içe aktarın
import { images } from '../../constants'

const App = () => {
  const [markers, setMarkers] = useState([]);
  const [selectedMarker, setSelectedMarker] = useState(null);
  const [modalVisible, setModalVisible] = useState(false);

  const fetchMarkers = async () => {
    try {
      const response = await fetch('http://192.168.159.138:8080/admin/allCar');
      const responseData = await response.json();
      if (responseData.isSuccess) {
        const markersData = responseData.data.map(item => ({
          carId: item.carId,
          type: item.type,
          carKilometer: item.carKilometer,
          x: parseFloat(item.y),
          y: parseFloat(item.x),
          statue: item.statue,
          previousDriver: item.previousDriver,
          amountOfFuel: item.amountOfFuel,
          lastServiceDateMonth: item.lastServiceDateMonth, // Assuming the date format is 'MM-DD'
          isRented: item.isRented,
          carPrice : item.carPrice,
        }));
        setMarkers(markersData);
      } else {
        console.error('Error fetching markers:', responseData.message);
      }
    } catch (error) {
      console.error('Error fetching markers:', error);
    }
  };
  
  useEffect(() => {
    const interval = setInterval(() => {
      fetchMarkers();
    }, 5000);
  
    return () => clearInterval(interval);
  }, []);


  const getMarkerIcon = (statue,isRented) => {
    if(isRented){
      return icons.carCrash;
    }else{
      switch (statue) {
        case 1:
          return icons.blackCar;
        case 2:
          return icons.orangeCar;
        case 3:
          return icons.pinkCar;
        default:
          return icons.car;
      }
    }
  };

  const handleMarkerPress = (marker) => {
    setSelectedMarker(marker);
    setModalVisible(true);
  };

  return (
    <View style={styles.container}>
      <MapView
        style={styles.map}
        initialRegion={{
          latitude: 41.0286,
          longitude: 28.8760,
          latitudeDelta: 0.1,
          longitudeDelta: 0.1,
        }}
      >
        {markers.map(marker => (
          <Marker
            key={marker.carId}
            title={marker.type}
            description={`Mileage: ${marker.carKilometer}, 
                          Previous Driver: ${marker.previousDriver}, 
                          Amount of Fuel: ${marker.amountOfFuel}, 
                          Last Service Date: ${marker.lastServiceDateMonth}, 
                          Is Rented: ${marker.isRented}`}
            coordinate={{
              latitude: marker.x,
              longitude: marker.y,
            }}
            onPress={() => handleMarkerPress(marker)}
          >
            <Image
              source={getMarkerIcon(marker.statue,marker.isRented)}
              style={{ width: 32, height: 32 }}
            />
          </Marker>
        ))}
      </MapView>
      <Image source={images.Algotur} style={styles.image} resizeMode='contain'/>
      <CustomModal
        visible={modalVisible}
        onClose={() => setModalVisible(false)}
        marker={selectedMarker}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  image: {
    position: 'absolute',
    top: 170,
    left: 120,
    right: 0,
    bottom: 0,
    width: 150,
  },
  map: {
    flex: 1,
  },
});

export default App;

/*
const App = () => {
  const [markers, setMarkers] = useState([]);
  const [selectedMarker, setSelectedMarker] = useState(null);
  const [modalVisible, setModalVisible] = useState(false);
  
  // Örnek işaretler dizisi
  const initialMarkers = [
    {
      id: 1,
      carType: 'mercedes',
      mileage: 32,
      xCoordinate: 41.1286,
      yCoordinate: 28.8760,
      statue: 3,
      previousDriver: 423,
      amountOfFuel: 32,
      lastServiceDate: '2023-03-04',
      isRented: false,
    },
    {
      id: 1,
      carType: 'mercedes',
      mileage: 32,
      xCoordinate: 41.0286,
      yCoordinate: 28.8760,
      statue: 2,
      previousDriver: 423,
      amountOfFuel: 32,
      lastServiceDate: '2023-03-04',
      isRented: false,
    },
    {
      id: 1,
      carType: 'mercedes',
      mileage: 32,
      xCoordinate: 41.0286,
      yCoordinate: 28.9760,
      statue: 1,
      previousDriver: 423,
      amountOfFuel: 32,
      lastServiceDate: '2023-03-04',
      isRented: false,
    },
    // Diğer işaretler buraya eklenebilir
  ];

  useEffect(() => {
    // Backend'den işaretlerin alınması simülasyonu
    setMarkers(initialMarkers);
  }, []);

  const getMarkerIcon = (statue) => {
    switch (statue) {
      case 1:
        return icons.blackCar;
      case 2:
        return icons.orangeCar;
      case 3:
        return icons.pinkCar;
      default:
        return icons.car;
    }
  };

  const handleMarkerPress = (marker) => {
    setSelectedMarker(marker);
    setModalVisible(true);
  };

  return (
    <View style={styles.container}>
      <MapView
        style={styles.map}
        initialRegion={{
          latitude: 41.0286,
          longitude: 28.8760,
          latitudeDelta: 0.1,
          longitudeDelta: 0.1,
        }}
      >
        {markers.map(marker => (
          <Marker
            key={marker.id}
            title={marker.carType}
            description={`Mileage: ${marker.mileage}, 
                          Previous Driver: ${marker.previousDriver}, 
                          Amount of Fuel: ${marker.amountOfFuel}, 
                          Last Service Date: ${marker.lastServiceDate}, 
                          Is Rented: ${marker.isRented}`}
            coordinate={{
              latitude: marker.xCoordinate,
              longitude: marker.yCoordinate,
            }}
            onPress={() => handleMarkerPress(marker)}
          >
             <Image
               source={getMarkerIcon(marker.statue)}
               style={{ width: 32, height: 32 }}
            />
          </Marker>
        ))}
      </MapView>

      <CustomModal
        visible={modalVisible}
        onClose={() => setModalVisible(false)}
        marker={selectedMarker}
      />
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
});

export default App;
*/