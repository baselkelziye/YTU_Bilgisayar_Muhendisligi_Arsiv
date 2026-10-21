import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import HomeScreen from './screens/HomeScreen';
import DetailScreen from './screens/DetailScreen';
import AboutScreen from './screens/AboutScreen';
import { FavoritesProvider } from './context/FavoritesContext';


const Stack = createNativeStackNavigator();

export default function App() {
  return (
    <FavoritesProvider>
      <NavigationContainer>
        <Stack.Navigator initialRouteName="Home">
          <Stack.Screen
  name="Home"
  component={HomeScreen}
  options={{
    title: 'FilmRadar',
    headerTitleAlign: 'center',
    headerTitleStyle: { fontSize: 20, fontWeight: 'bold' },
    headerStyle: { elevation: 0, shadowOpacity: 0, borderBottomWidth: 0, height: 54, backgroundColor: '#fff' }
  }}
/>
     <Stack.Screen name="Detail" component={DetailScreen} options={{ title: 'Film Detayı' }} />
          <Stack.Screen name="About" component={AboutScreen} options={{ title: 'Hakkında' }} />
        </Stack.Navigator>
      </NavigationContainer>
    </FavoritesProvider>
  );
}
