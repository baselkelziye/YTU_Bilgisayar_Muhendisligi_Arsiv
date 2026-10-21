import { StatusBar } from 'expo-status-bar';
import {  Image, ScrollView, Text, View } from 'react-native';
import { Link } from 'expo-router';
import { SafeAreaView } from 'react-native-safe-area-context';
import { images } from '../constants';
import { Redirect, router } from "expo-router";
import CustomButton from '../components/CustomButton';


export default function App() {
  return (
    <SafeAreaView className = "bg-primary h-full">
      <ScrollView contentContainerStyle = {{height : '%100'}}>
        <View className ="w-full justify-center items-center min-h-[85vh] px-4">
            <Image 
               source={images.logo}
               className = "w-[2500px] h-[250px]"
               resizeMode='contain'
               
            />
            <View className="relative mt-5">
            <Text className="text-3xl text-white font-bold text-center">
              Unlock Your Journey{"\n"}
              Rent with Ease{" "}
              <Text className="text-secondary-200">ALGOTUR</Text>
            </Text>

            <Image
              source={images.path}
              className="w-[136px] h-[15px] absolute -bottom-2 -right-7"
              resizeMode="contain"
            />
          </View>
          <Text className="text-sm font-pregular text-gray-100 mt-7 text-center">
            Where Convenience Meets Adventure: Drive into Exploration Unlimited with ALGOTUR
          </Text>
          <CustomButton
            title="Sign In"
            handlePress={() => router.push("/sign-in")}
            containerStyles="w-full mt-7"
          />
             <CustomButton
            title="Sign Up"
            handlePress={() => router.push("/sign-up")}
            containerStyles="w-full mt-7"
          />
        </View>  
        <StatusBar backgroundColor="#161622" style="light" />
      </ScrollView>
      <StatusBar backgroundColor="#161622" style="light" />
    </SafeAreaView>
  );
}

