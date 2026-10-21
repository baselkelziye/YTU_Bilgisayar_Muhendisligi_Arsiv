import { View, Text, SafeAreaView, ScrollView } from 'react-native'
import React from 'react'
import {  router } from "expo-router";
import CustomButton from '../../components/CustomButton'
import packageJson from '../../package.json';
const version = packageJson.version;


const menu = () => {
  return (
    <SafeAreaView className = "h-full bg-gray-100">
      <ScrollView contentContainerStyle = {{height : '%100'}}>
          <View className ="w-full justify-top  min-h-[85vh] my-6">
          <CustomButton 
          title="Contact"
          containerStyles="rounded-none bg-gray-100 justify-start border-b-2 border-gray-200 mt-7	min-h-[30px]"
          textStyles="text-left text-sm"
          handlePress={() => router.push("/MenuComponents/contact")}
          />
           <CustomButton 
          title="Cars"
          containerStyles="rounded-none bg-gray-100 justify-start border-b-2 border-gray-200 mt-7	min-h-[30px]"
          textStyles="text-left text-sm"
          handlePress={() => router.push("/MenuComponents/cars")}
          />
           <CustomButton 
          title="Frequently Asked Questions"
          containerStyles="rounded-none bg-gray-100 justify-start border-b-2 border-gray-200 mt-7	min-h-[30px]	"
          textStyles="text-left text-sm"
          handlePress={() => router.push("/MenuComponents/FAS")}
          />
           <CustomButton 
          title="Service Area"
          containerStyles="rounded-none bg-gray-100 justify-start border-b-2 border-gray-200 mt-7	min-h-[30px]	"
          textStyles="text-left text-sm"
          handlePress={() => router.push("/MenuComponents/serviceArea")}
          />
           <CustomButton 
          title="Contracts"
          containerStyles="rounded-none bg-gray-100 justify-start border-b-2 border-gray-200 mt-7	min-h-[30px]	 "
          textStyles="text-left text-sm"
          handlePress={() => router.push("/MenuComponents/contracts")}
          />
          <Text className=" mt-6 text-center">Version : {version}</Text>
         </View>
      </ScrollView>
    </SafeAreaView>
    
  )
}

export default menu