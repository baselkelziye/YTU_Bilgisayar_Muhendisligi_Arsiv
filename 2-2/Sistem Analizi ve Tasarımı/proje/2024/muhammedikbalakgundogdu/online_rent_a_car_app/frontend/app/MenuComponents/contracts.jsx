import { View, Text,Image } from 'react-native'
import React from 'react'
import { images } from '../../constants'

const contract = () => {
  return (
    <View>
      <Text>In our database we can reach your personal information to give you a better service all users that use this application accpet this rule.</Text>
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

export default contract