import { View, Text,Image } from 'react-native'
import React from 'react'
import { Tabs , Redirect } from 'expo-router'

import { icons } from '../../constants'



const TabIcon = ({ icon, color, name, focused}) =>{
    return(
        <View className= "items-center justify-center gap-0.5 ">
            <Image
                 source ={icon}
                 resizeMode="contain"
                 tintColor={color}
                className='w-6 h-6'
            />
            <Text className = {`${focused ? 'font-psemibold' :'font-pregular'} text-xs` }style={{color : color}}>
                    {name}
            </Text>
        </View>
        
    )
}

const TabLayout = () => {
  return (
   <>
        <Tabs 
        screenOptions={
            {
                tabBarShowLabel : false,
                tabBarActiveTintColor : '#FFA001',
                tabBarInactiveTintColor :'#CDCDE0',
                tabBarStyle : {
                            backgroundColor :'#161622',
                            borderTopWidth : 1,
                            borderTopColor : '#232533',
                            height : 60
                }
            }
        }
        >
            <Tabs.Screen
                name = "home" 
                options={{
                    title: 'home',
                    headerShown : false,
                    tabBarIcon : ({color,focused}) =>(
                        <TabIcon
                            icon ={icons.home}
                            color ={color}
                            name = "Home"
                        />
                    )
                }} 
            />
             <Tabs.Screen
                name = "profile" 
                options={{
                    title: 'Profile',
                    headerShown : false,
                    tabBarIcon : ({color,focused}) =>(
                        <TabIcon
                            icon ={icons.profile}
                            color ={color}
                            name = "Profile"
                        />
                    )
                }} 
            />
            <Tabs.Screen
                name = "menu" 
                options={{
                    title: 'Menu',
                    headerShown : false,
                    tabBarIcon : ({color,focused}) =>(
                        <TabIcon
                            icon ={icons.menu}
                            color ={color}
                            name = "Menu"
                        />
                    )
                }} 
            />
        </Tabs>
   </>
  )
}

export default TabLayout