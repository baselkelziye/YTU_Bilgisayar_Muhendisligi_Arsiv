import { View, Text, SafeAreaView, ScrollView, Alert } from 'react-native'
import React, { useState } from 'react'
import FormField from '../components/FormField'
import CustomButton from '../components/CustomButton';

const homeAdmin = () => {

  const [form, setForm] = useState({
    type: "",
    fuel: "",
  });
  
  const [control, setControl] = useState({
    type: "",
    date: "",
  });

  const [discount, setDiscount] = useState({
    type: "",
    amount: "",
  });

  const [upadtePrice, setUpadtePrice] = useState({
    type: "",
    amount: "",
  });
  const [repairCar, setrepairCar] = useState({
    type: "",
  });

  const [carAdd, setCarAdd] = useState({
    car_is_rented: "",
    car_kilometer: "",
    car_last_service: "",
    car_previous_driver: "",
    car_price: "",
    car_statue: "",
    car_type: "",
    car_x_coordinate: "",
    car_y_coordinate: "",
  });

  const [deleteCar, setDeleteCar] = useState({
    id: "",
  });

  const handleDeleteCar = async () => {
    try {
      const response = await fetch(`http://192.168.159.138/admin/deleteCar/${deleteCar.id}`, {
        method: 'DELETE',
      });
      const data = await response.json();
      if (response.ok) {
        Alert.alert('Success', data.message);
      } else {
        Alert.alert('Error', data.message);
      }
    } catch (error) {
      console.error('Error deleting car:', error);
      Alert.alert('Error', 'An error occurred while deleting car. Please try again later.');
    }
  };

  const handleAddNewCar = async () => {
    try {
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
    } catch (error) {
      console.error('Error adding car:', error);
      Alert.alert('Error', 'An error occurred while adding car. Please try again later.');
    }
  };

  const handleFuelProcess = async () => {
    try {
      const response = await fetch(`http://192.168.159.138:8080/admin/updateCar1`, { //updateCar fuel islemi
        method: 'PUT',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          type: form.type, // Güncellenecek aracın ID'si
          amountOfFuel: form.fuel, // Yeni yakıt miktarı
        }),
      });
      const data = await response.json();
      if (response.ok) {
        Alert.alert('Success', data.message);
      } else {
        Alert.alert('Error', data.message);
      }
    } catch (error) {
      console.error('Error updating fuel:', error);
      Alert.alert('Error', 'An error occurred while updating fuel. Please try again later.');
    }
  };

  const handleDiscountProcess = async () => {
    try {
      const response = await fetch(`http://192.168.159.138:8080/admin/updateCar2`, { //updateCar fuel islemi
        method: 'PUT',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          type: discount.type, // Güncellenecek aracın ID'si
          carPrice: discount.amount, // Yeni yakıt miktarı
        }),
      });
      const data = await response.json();
      if (response.ok) {
        Alert.alert('Success', data.message);
      } else {
        Alert.alert('Error', data.message);
      }
    } catch (error) {
      console.error('Error updating fuel:', error);
      Alert.alert('Error', 'An error occurred while updating fuel. Please try again later.');
    }
  };

  const handlePriceProcess = async () => {
    try {
      const response = await fetch(`http://192.168.159.138:8080/admin/updateCar2`, { //updateCar fuel islemi
        method: 'PUT',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          type: upadtePrice.type, // Güncellenecek aracın ID'si
          carPrice: upadtePrice.amount, // Yeni yakıt miktarı
        }),
      });
      const data = await response.json();
      if (response.ok) {
        Alert.alert('Success', data.message);
      } else {
        Alert.alert('Error', data.message);
      }
    } catch (error) {
      console.error('Error updating fuel:', error);
      Alert.alert('Error', 'An error occurred while updating fuel. Please try again later.');
    }
  };

  const handleDateProcess = async () => {
    try {
      const response = await fetch(`http://192.168.159.138:8080/admin/updateCar3`, { //updateCar fuel islemi
        method: 'PUT',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          type: control.type, // Güncellenecek aracın ID'si
          lastServiceDateMonth: control.date, // Yeni yakıt miktarı
        }),
      });
      const data = await response.json();
      if (response.ok) {
        Alert.alert('Success', data.message);
      } else {
        Alert.alert('Error', data.message);
      }
    } catch (error) {
      console.error('Error updating fuel:', error);
      Alert.alert('Error', 'An error occurred while updating fuel. Please try again later.');
    }
  };

  const handleRepairProcess = async () => {
    try {
      const response = await fetch(`http://192.168.159.138:8080/admin/updateCar5`, { //updateCar fuel islemi
        method: 'PUT',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          type: repairCar.type, 
          isRented : false, 
        }),
      });
      const data = await response.json();
      if (response.ok) {
        Alert.alert('Success', data.message);
      } else {
        Alert.alert('Error', data.message);
      }
    } catch (error) {
      console.error('Error updating fuel:', error);
      Alert.alert('Error', 'An error occurred while updating fuel. Please try again later.');
    }
  };

  return (
    <SafeAreaView className="bg-primary h-full">
      <ScrollView contentContainerStyle={{ height: '1000%' }} >
        <View className="w-full justify-top  min-h-[85vh] px-4 my-6">
          <Text>Welcome Admin</Text>

          <FormField
            title="Car type"
            value={form.type}
            handleChangeText={(e) => setForm({ ...form, type: e })}
            otherStyles="mt-7"
          />
          <FormField
            title="Fuel Amount"
            value={form.fuel}
            handleChangeText={(e) => setForm({ ...form, fuel: e })}
            otherStyles="mt-7"
          />
           <CustomButton
            title="Fuel Process"
            handlePress={handleFuelProcess} //yapilacak islem
            containerStyles="mt-7" //--------------------------------------------------------
          /> 
          
          <FormField
            title="Car Type"
            value={control.type}
            handleChangeText={(e) => setControl({ ...control, type: e })}
            otherStyles="mt-7"
            
          />
          <FormField
            title="Control Date"
            value={control.date}
            handleChangeText={(e) => setControl({ ...control, date: e })}
            otherStyles="mt-7"
          />
           <CustomButton
            title="Control Process"
            handlePress={handleDateProcess} //yapilacak islem
            containerStyles="mt-7"
          />

          <FormField
            title="Car Type"
            value={discount.type}
            handleChangeText={(e) => setDiscount({ ...discount, type: e })}
            otherStyles="mt-7"
           
          />
          <FormField
            title="discount amount"
            value={discount.amount}
            handleChangeText={(e) => setDiscount({ ...discount, amount: e })}
            otherStyles="mt-7"
            keyboardType="numeric"
          />
          <CustomButton
            title="Discount Process"
            handlePress={handleDiscountProcess} //yapilacak islem
            containerStyles="mt-7"
          />

          <FormField
            title="Car Type"
            value={upadtePrice.type}
            handleChangeText={(e) => setUpadtePrice({ ...upadtePrice, type: e })}
            otherStyles="mt-7"
            
          />
          <FormField
            title="Update Price amount"
            value={upadtePrice.amount}
            handleChangeText={(e) => setUpadtePrice({ ...upadtePrice, amount: e })}
            otherStyles="mt-7"
            keyboardType="numeric"
          />
          <CustomButton
            title="Update Price Process"
            handlePress={handlePriceProcess} //yapilacak islem
            containerStyles="mt-7"
          />



          
          <FormField // car add -----------------------------------------------------------------------------------------------------------------------
            title="Car Kiloemeter"
            value={carAdd.car_kilometer}
            handleChangeText={(e) => setCarAdd({ ...carAdd, car_kilometer: e })}
            otherStyles="mt-7"
            keyboardType="numeric"
          />
          <FormField
            title="Car Last Service"
            value={carAdd.car_last_service}
            handleChangeText={(e) => setCarAdd({ ...carAdd, car_last_service: e })}
            otherStyles="mt-7"
            keyboardType="numeric"
          />
          <FormField
            title="Car Price Per Minute"
            value={carAdd.car_price}
            handleChangeText={(e) => setCarAdd({ ...carAdd, car_price: e })}
            otherStyles="mt-7"
            keyboardType="numeric"
          />
          <FormField
            title="Car Status"
            value={carAdd.car_statue}
            handleChangeText={(e) => setCarAdd({ ...carAdd, car_statue: e })}
            otherStyles="mt-7"
            keyboardType="numeric"
          />
          <FormField
            title="Car Model"
            value={carAdd.car_type}
            handleChangeText={(e) => setCarAdd({ ...carAdd, car_type: e })}
            otherStyles="mt-7"
          />

          <CustomButton
            title="Add New Car"
            handlePress={handleAddNewCar} //yapilacak islem
            containerStyles="mt-7"
          />

          <FormField 
            title="Car Id"
            value={deleteCar.id}
            handleChangeText={(e) => setDeleteCar({ ...deleteCar, id: e })}
            otherStyles="mt-7"
            keyboardType="numeric"
          />

          <CustomButton
            title="Delete Car"
            handlePress={handleDeleteCar} //yapilacak islem
            containerStyles="mt-7 bg-red-100"
          />

          <FormField 
            title="Car type"
            value={repairCar.type}
            handleChangeText={(e) => setrepairCar({ ...repairCar, type: e })}
            otherStyles="mt-7"
          />
            <CustomButton
            title="Repair Car"
            handlePress={handleRepairProcess} //yapilacak islem
            containerStyles="mt-7 bg-green-100"
          />
        </View>
      </ScrollView>
    </SafeAreaView>
  )
}

export default homeAdmin