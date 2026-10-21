import { View, Text,Image  } from 'react-native'
import React from 'react'
import { Link } from 'expo-router'
import { images } from '../../constants'

const FAS = () => {
  return (
    <View>
      <Text>Why sometimes i cant see car in map ?</Text>
      <Text>Because we render map at every 5 seconds and in first enter to map taking car informations from database can take 5 seconds</Text>
      <Text></Text>
      <Text>Why sometimes i cant see my informations in profile screen ?</Text>
      <Text>Because we render profile screnn at every 5 seconds and in first enter to profile taking profile informations from database can take 5 seconds</Text>
      <Text></Text>
      <Text>Why i cant see my informations in profile screen and pay money to my account?</Text>
      <Text>Because you can enter your informations at wrong type or design or your informations cant include unvalid characters</Text>
      <Text>You can contact with us at this situation with  <Link className ="text-secondary" href = "mailto:muhammedikbalcmp@gmail.com?subject=Wrong Register&body=Mesaj metni">Muhammed İkbal AKGÜNDOĞDU</Link></Text>
      <Text></Text>
      <Text></Text>
      <View className="w-full justify-top items-center">
      <Image className=" w-[115px] h-[150px]" source={images.Algotur} resizeMode='contain'/>
      <Text></Text>
      <Text></Text>
      <Text>  Have a nice day...</Text>
      </View>
      
    </View>
  )
}

export default FAS