import React, { useEffect, useState } from "react";
import { View, Text, ScrollView, Alert } from "react-native";
import AsyncStorage from '@react-native-async-storage/async-storage'; 
import { SafeAreaView } from "react-native-safe-area-context";
import CustomButton from "../../components/CustomButton";
import FormField from "../../components/FormField";

const ProfileScreen = () => {
  const [userData, setUserData] = useState(null); // State to hold user data

  const [formValues, setFormValues] = useState({
    creditCardNumber: '',
    cvv: '',
    amount: ''
  });



  const fetchUserData = async () => {
    try {
      const telNumber = await getMarkerFromStorage();
      const response = await fetch(`http://192.168.159.138:8080/api/userInfo/${telNumber}`);
      const responseData = await response.json();
      if (responseData.isSuccess) {
        setUserData({  
          name: responseData.data.name,
          surname: responseData.data.surname,
          telNumber: responseData.data.telNumber,
          money: responseData.data.money,
          drivingPoint: responseData.data.drivingPoint,
          drivingLicense: responseData.data.drivingLicense
        });
      } else {
        console.error('Error fetching user data:', responseData.message);
      }
    } catch (error) {
      console.error('Error fetching user data:', error);
    }
  };
  
  useEffect(() => {
    const interval = setInterval(() => {
      fetchUserData();
    }, 5000);
  
    return () => clearInterval(interval);
  }, []);


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

  const handleAddMoney = async () => {
    try {
      const telNumber1 = await getMarkerFromStorage();
      console.log("amount"+formValues.amount)
      console.log("cvv"+formValues.cvv)
      console.log("number"+formValues.creditCardNumber)
      const response = await fetch('http://192.168.159.138:8080/creditCard/addMoney', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({
          
          amountOfPaymentDTO: {
            amountOfPayment: parseFloat(formValues.amount)+userData.money
          },
          userDTO: {
            telNumber: telNumber1 // Assuming you have userData from somewhere
          },
          creditCardDTO: {
            cardNumber: formValues.creditCardNumber,
            cvv: formValues.cvv
          }
         
        })
      });

      const responseData = await response.json();
      if (responseData.isSuccess) {
        Alert.alert('Success adding money:', responseData.message); // Başarı mesajını göster
      } else {
        console.error('Error adding money:', responseData.message);
        Alert.alert('Error adding money:', responseData.message); // Hata mesajını göster
      }
    } catch (error) {
      console.error('Error adding money:', error);
    }
  };

  return (
    <SafeAreaView className = "bg-primary"style={{ flex: 1 }}>
      <ScrollView>
        <View style={{ justifyContent: 'center', alignItems: 'center', minHeight: '85vh', paddingHorizontal: 4, marginTop: 6 }}>
          {userData ? (
            <>
              <Text className="text-secondary-100" style={{ fontSize: 24 }}> Name:   {userData.name}</Text>
              <Text className="text-secondary-100" style={{ fontSize: 24 }}> Last Name:   {userData.surname}</Text>
              <Text className="text-secondary-100" style={{ fontSize: 24 }}> Driving License:   {userData.drivingLicense}</Text>
              <Text className="text-secondary-100" style={{ fontSize: 24 }}> Driving Point:   {userData.drivingPoint}</Text>
              <Text className="text-secondary-100" style={{ fontSize: 24 }}> Money:   {userData.money} $</Text>
            </>
          ) : (
            <Text>Loading...</Text>
          )}
          <FormField
            title="Credit Card Number"
            value={formValues.creditCardNumber}
            placeholder="Enter your credit card number"
            handleChangeText={(text) => setFormValues({ ...formValues, creditCardNumber: text })}
            otherStyles="mt-7"
            keyboardType="numeric"
          />
          <FormField
            title="CVV"
            value={formValues.cvv}
            placeholder="Enter your CVV"
            handleChangeText={(text) => setFormValues({ ...formValues, cvv: text })}
            otherStyles="mt-7"
            keyboardType="numeric"
          />
          <FormField
            title="Amount"
            value={formValues.amount}
            placeholder="Enter the amount"
            handleChangeText={(text) => setFormValues({ ...formValues, amount: text })}
            otherStyles="mt-7"
            keyboardType="numeric"
          />
          
          <CustomButton
            title="Add Money"
            handlePress={handleAddMoney}
            
          />
        </View>
      </ScrollView>
    </SafeAreaView>
  );
  
};

export default ProfileScreen;
