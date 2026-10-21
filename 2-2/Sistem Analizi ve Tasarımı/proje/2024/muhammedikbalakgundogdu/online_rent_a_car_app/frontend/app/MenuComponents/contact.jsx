import { View, Text,Image } from 'react-native'
import React from 'react'
import { Link } from 'expo-router'
import { images } from '../../constants'

const contact = () => {
  return (
    <View>
      <Text>You can contact with us with gmail 7/24</Text>
      <Text></Text>
      <Link className ="text-secondary" href = "mailto:muhammedikbalcmp@gmail.com?subject=Konu&body=Mesaj metni">Muhammed İkbal AKGÜNDOĞDU</Link>
      <Text></Text>
      <Link className ="text-secondary" href="mailto:omeeryldrmm03@gmail.com?subject=Konu&body=Mesaj metni">Ömer Faruk YILDIRIM</Link>
      <Text></Text>
      <Link className ="text-secondary" href="mailto:eroglufurkan1409@gmail.com?subject=Konu&body=Mesaj metni">Furkan EROĞLU</Link>
      <Text></Text>
      <Link className ="text-secondary" href="mailto:mahmutdemir2003@hotmail.com?subject=Konu&body=Mesaj metni">Mahmut DEMİR</Link>
      <Text></Text>
      <Link className ="text-secondary" href="mailto:alperenyasar21@gmail.com?subject=Konu&body=Mesaj metni">Alperen YAŞAR</Link>
      <Text></Text>
      <Text>We reply all mails at 24 hour</Text>
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

export default contact