import { useEffect, useState } from "react";
import { Link, router } from "expo-router";
import { SafeAreaView } from "react-native-safe-area-context";
import { View, Text, ScrollView, Dimensions, Alert, Image } from "react-native";
import { images } from '../../constants'
import FormField from '../../components/FormField'
import CustomButton from "../../components/CustomButton";
import AsyncStorage from '@react-native-async-storage/async-storage';

const SignUp = () => {
  const [isSubmitting, setSubmitting] = useState(false);
  const [form, setForm] = useState({
    phoneNumber: "",
    password: "",
    name:"",
    surname:"",
    driverLicense:"",
  });
  
  const savePhoneNumberToStorage = async (phoneNumber) => {
    try {
      await AsyncStorage.setItem('phoneNumber', phoneNumber); // AsyncStorage'e phoneNumber'ı kaydet
      console.log('PhoneNumber kaydedildi:', phoneNumber); // Başarılı bir şekilde kaydedildiğinde konsola mesaj yazdır
    } catch (error) {
      console.error('Hata:', error); // Hata oluştuğunda konsola hata mesajını yazdır
    }
  };

  useEffect(() => {
    if (form.phoneNumber) { // Eğer phoneNumber varsa
      savePhoneNumberToStorage(form.phoneNumber); // AsyncStorage'e phoneNumber'ı kaydet
    }
  }, [form.phoneNumber]);

  const submit = async () => {
    // Formu gönderme işlemi başlat
    setSubmitting(true);

    try {
      // Giriş bilgilerini kontrol et
      if (
        form.phoneNumber === "" ||
        form.password === "" ||
        form.name === "" ||
        form.surname === "" ||
        form.driverLicense === ""
      ) {
        Alert.alert("Error", "Please fill in all fields");
        return;
      }

      // Backend ile kayıt işlemini gerçekleştir
      const response = await fetch('http://192.168.159.138:8080/api/saveUser', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          telNumber: form.phoneNumber,
          password: form.password,
          name: form.name,
          surname: form.surname,
          drivingLicense: form.driverLicense,
        }),
      });

      const responseData = await response.json();
      console.log(responseData)
      if (response.ok || responseData.isSuccess) {
        // Başarılı kayıt durumunda router ile başka bir ekrana yönlendir
        savePhoneNumberToStorage(form.phoneNumber)
        router.push("/home");
      } else {
        // Sunucudan gelen hata mesajını göster
        Alert.alert("Error", responseData.message);
      }
    } catch (error) {
      // Hata durumunda genel hata mesajını göster
      console.error('Error signing up:', error);
      Alert.alert("Error", "An error occurred while signing up. Please try again later.");
    } finally {
      // Form gönderme işlemi tamamlandı, tekrar submit olabilir
      setSubmitting(false);
    }
  };
  
  return (
    <SafeAreaView className = "bg-primary h-full" >
      <ScrollView contentContainerStyle = {{height : '%100'}}>
        <View className ="w-full justify-top  min-h-[85vh] px-4 my-6">
          <Image className=" w-[115px] h-[150px]" source={images.Algotur} resizeMode='contain'/>
          <Text className="text-secondary text-2xl">Sign Up to ALGOTUR</Text>
          <FormField
            title="Phone Number"
            value={form.phoneNumber}
            handleChangeText={(e) => setForm({ ...form, phoneNumber: e })}
            otherStyles="mt-7"
            keyboardType="numeric"
          />

          <FormField
            title="Name"
            value={form.name}
            handleChangeText={(e) => setForm({ ...form, name: e })}
            otherStyles="mt-7"
          />

          <FormField
            title="SurName"
            value={form.surname}
            handleChangeText={(e) => setForm({ ...form, surname: e })}
            otherStyles="mt-7" 
          />
          <FormField
            title="Password"
            value={form.password}
            handleChangeText={(e) => setForm({ ...form, password: e })}
            otherStyles="mt-7"
          />
          <FormField
            title="Driver License ID"
            value={form.driverLicense}
            handleChangeText={(e) => setForm({ ...form, driverLicense: e })}
            otherStyles="mt-7"
          />

          <CustomButton
            title="Sign Up"
            handlePress={submit}
            containerStyles="mt-7"
            isLoading={isSubmitting}
            
          />
          <View className="flex justify-center pt-5 flex-row gap-2">
            <Text className="text-lg text-gray-100 font-pregular">
              Have an account already?
            </Text>
            <Link
              href="/sign-in"
              className="text-lg font-psemibold text-secondary"
            >
              Sign in
            </Link>
          </View>
        </View>
        
      </ScrollView>
    </SafeAreaView>
  )
}

export default SignUp