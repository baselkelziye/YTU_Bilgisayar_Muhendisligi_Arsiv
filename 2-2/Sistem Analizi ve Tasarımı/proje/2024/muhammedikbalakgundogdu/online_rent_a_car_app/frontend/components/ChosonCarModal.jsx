import React, { useState } from 'react';
import { View, Modal, TouchableOpacity, Text } from 'react-native';
import CustomButton from './CustomButton';
import HireModal from './HireModal'
import { router } from 'expo-router';



const CustomModal = ({ visible, onClose, marker }) => {
  const [hireModalVisible, setHireModalVisible] = useState(false); // Hire modalının görünürlüğünü tutmak için bir state

  let content;
          if(marker?.statue==3){
               content = <Text className="text-secondary text-xl font-pbold">Statue 3</Text>
          }else if(marker?.statue==2){
            content = <Text className="text-secondary text-xl font-pbold" >Statue 2</Text>
          }else{
            content = <Text className="text-secondary text-xl font-pbold">Statue 1</Text>
          }
          const handleHirePress = async () => {
            
            try {
              const response = await fetch('http://192.168.91.138:8080/admin/updateCar4', {
                method: 'PUT', // PUT metodu kullanılacak
                headers: {
                  'Content-Type': 'application/json'
                },
                body: JSON.stringify({
                  type: marker.type,
                  isRented: true // Kaza durumunda aracın kiralık durumu false olarak güncelleniyor
                })
              });
              const data = await response.json();
              if (response.ok ) {
                console.log('İşlem başarılı:', data);
                // İsteğin başarıyla tamamlandığını kullanıcıya bildirebilirsiniz
              } else {
                console.error('HTTP hatası:', response.status);
                // Hata durumunda kullanıcıya bir hata mesajı gösterebilirsiniz
              }
            } catch (error) {
              console.error('İstek hatası:', error);
              // Hata durumunda kullanıcıya bir hata mesajı gösterebilirsiniz
            }

            setHireModalVisible(true); // Yeni modalı görünür yap
            onClose(); // Eski modalı kapat
          };

          const reportCrash = async () => {
            
              try {
                const response = await fetch('http://192.168.91.138:8080/admin/updateCar4', {
                  method: 'PUT', // PUT metodu kullanılacak
                  headers: {
                    'Content-Type': 'application/json'
                  },
                  body: JSON.stringify({
                    type: marker.type,
                    isRented: true // Kaza durumunda aracın kiralık durumu false olarak güncelleniyor
                  })
                });
                const data = await response.json();
                if (response.ok ) {
                  console.log('İşlem başarılı:', data);
                  // İsteğin başarıyla tamamlandığını kullanıcıya bildirebilirsiniz
                } else {
                  console.error('HTTP hatası:', response.status);
                  // Hata durumunda kullanıcıya bir hata mesajı gösterebilirsiniz
                }
              } catch (error) {
                console.error('İstek hatası:', error);
                // Hata durumunda kullanıcıya bir hata mesajı gösterebilirsiniz
              }
            
            onClose(); // Eski modalı kapat
          };
  return (
    <>
    <Modal
      animationType="slide"
      transparent={true}
      visible={visible}
      onRequestClose={onClose}
    >
      <TouchableOpacity // Dışarı tıklandığında modalı kapatmak için TouchableOpacity kullanabiliriz
        activeOpacity={1} // Opaklık efektini kaldırır
        style={{ flex: 1, justifyContent: 'center', alignItems: 'center', backgroundColor: 'rgba(0, 0, 0, 0.5)' }}
        onPress={onClose} // Dışarı tıklandığında onClose fonksiyonunu çağırır
      >
        <View className="bg-primary "style={{ padding: 20, borderRadius: 10 }}>
          {content}
          <Text className="text-secondary text-xl font-pregular">Car Type: {marker?.type}</Text>
          <Text className="text-secondary text-xl font-pregular">Mileage: {marker?.carKilometer}</Text>
          <Text className="mb-5 text-secondary text-xl font-pregular">Price: {marker?.carPrice}</Text>

            <CustomButton
            title="Hire"
            handlePress={handleHirePress}
            containerStyles="mt-7"
          /> 
          <CustomButton
            title="Report Crash"
            handlePress={reportCrash}
            containerStyles="mt-7 bg-red-100"
          /> 
          {/* Diğer bilgileri buraya ekleyin */}
        </View>
      </TouchableOpacity>
    </Modal>
    {hireModalVisible && <HireModal visible={hireModalVisible} onClose={() => setHireModalVisible(false)} marker={marker} />}
    </>
  );
};

export default CustomModal;