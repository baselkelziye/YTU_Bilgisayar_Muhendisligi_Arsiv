import React, { useState, useEffect } from 'react';
import { Modal, View, Text, TouchableOpacity, Alert } from 'react-native';
import CustomButton from './CustomButton';
import { router } from 'expo-router';
import { Route } from 'expo-router/build/Route';
import AsyncStorage from '@react-native-async-storage/async-storage';

const getMarkerFromStorage = async () => {
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

const HireModal = ({ visible, onClose, marker }) => {
  const [startTime, setStartTime] = useState(null); // Hire modalının açıldığı zamanı tutmak için bir state
  const [elapsedTime, setElapsedTime] = useState(0); // Geçen zamanı tutmak için bir state
  const [carKilometer, setMileage] = useState(0); // Mileage değerini tutmak için bir state
  const [userData, setUserData] = useState(null); // State to hold user data
  
  const handleAddMoney = async () => {
    try {
      const calculatedAmount = parseFloat(elapsedTime)
      
      console.log("Calculated amount:", calculatedAmount);
      console.log("price amount:", marker.carPrice);
      console.log("sda"+ calculatedAmount * marker.carPrice / 60)
      const telNumber1 = await getMarkerFromStorage();
      const response = await fetch('http://192.168.91.138:8080/creditCard/payment', {
        method: 'PUT',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({
          amountOfPaymentDTO: {
            amountOfPayment: calculatedAmount* marker.carPrice / 60
          },
          userDTO: {
            telNumber: telNumber1 // Assuming you have userData from somewhere
          }, 
        })
      });
  
      const responseData = await response.json();
      if (response.ok && responseData.isSuccess) {
        Alert.alert('Success adding money:', responseData.message); // Başarı mesajını göster
      } else {
        console.error('Error adding money:', responseData.message);
        Alert.alert('Error adding money:', responseData.message); // Hata mesajını göster
      }
    } catch (error) {
      console.error('Error adding money:', error);
    }
  };
  
const saveMarkerToStorage = async (marker1) => {
  try {
    await AsyncStorage.setItem('marker', JSON.stringify(marker1));
    console.log('Marker kaydedildi:', marker1);
  } catch (error) {
    console.error('1234 Hata:', error);
  }
};
  useEffect(() => {
    if (marker) {
      setMileage(marker.carKilometer); // Marker değiştiğinde mileage değerini güncelle
    }
  }, [marker]);

  useEffect(() => {
    if (visible) {
      setStartTime(Date.now()); // Hire modalı açıldığında başlangıç zamanını belirle
    } else {
      setStartTime(null); // Hire modalı kapatıldığında başlangıç zamanını sıfırla
    }
  }, [visible]);

  useEffect(() => {
    let timer;
    if (startTime) {
      // Başlangıç zamanı varsa, geçen zamanı hesapla ve 1 saniye aralıklarla güncelle
      timer = setInterval(() => {
        const currentTime = Date.now();
        const elapsedTimeInSeconds = Math.floor((currentTime - startTime) / 1000);
        setElapsedTime(elapsedTimeInSeconds);

      }, 1000);
    }
    return () => clearInterval(timer); // Komponent kaldırıldığında timer'ı temizle
  }, [startTime]);

  // Süreyi saat, dakika ve saniye cinsine dönüştür
  const hours = Math.floor(elapsedTime / 3600);
  const minutes = Math.floor((elapsedTime % 3600) / 60);
  const seconds = elapsedTime % 60;

  

  return (
    <Modal
      animationType="slide"
      transparent={true}
      visible={visible}
      onRequestClose={onClose}
    >
      <TouchableOpacity
        activeOpacity={1}
        style={{ flex: 1, justifyContent: 'center', alignItems: 'center', backgroundColor: 'rgba(0, 0, 0, 0.5)' }}
        onPress={onClose}
      >
        <View className="bg-primary" style={{ padding: 20, borderRadius: 10 }}>
          <Text></Text>
          <Text className="text-2xl text-secondary mb-10 p-10">{hours.toString().padStart(2, '0')} : {minutes.toString().padStart(2, '0')} : {seconds.toString().padStart(2, '0')} </Text>
          <Text>Mileage: {carKilometer}</Text> 
          <CustomButton
            title="Finish Hire"
            handlePress={() => {
              marker.carKilometer += ~~(elapsedTime / 5);
              marker.amountOfFuel -= elapsedTime / 10;
              console.log("marker.mileage burada hire modaldayız ste")
              console.log(marker.carKilometer)
              saveMarkerToStorage(marker)
              handleAddMoney();
              onClose();
              router.push("/MapSelection",marker)

            }}
            containerStyles={{ marginTop: 10 }}
          />
        </View>
      </TouchableOpacity>
    </Modal>
  );
};

export default HireModal;
