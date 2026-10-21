import { View, Text,Image } from 'react-native'
import React from 'react'
import { images } from '../../constants'

const serviceArea = () => {
  return (
    <View>
      <Text>We can give service in istanbul you cant take our can and park out of istanbul</Text>
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

export default serviceArea