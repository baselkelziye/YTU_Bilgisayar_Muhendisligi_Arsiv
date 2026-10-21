import { View, Text,Image } from 'react-native'
import React from 'react'
import { images } from '../../constants'

const cars = () => {
  return (
    <View>
      <Text>We have 3 statue of Car : pink, orange and black</Text>
      <Text>Pink cars is most valuable car </Text>
      <Text>Black cars is less valuable car</Text>
      <Text></Text>
      <Text></Text>
      <View className="w-full justify-top  items-center">
      <Image className=" w-[115px] h-[150px]" source={images.Algotur} resizeMode='contain'/>
      <Text></Text>
      <Text></Text>
      <Text>  Have a nice day...</Text>
      </View>
    </View>
  )
}

export default cars