import { View, Text } from 'react-native'
import React from 'react'

window.ipAddress = 'http://192.168.159.138:8080/';
// NetworkService.js
class NetworkService {
  async fetchData(endpoint) {
    const response = await fetch(`${window.ipAddress}${endpoint}`);
    return response.json();
  }
}

export default NetworkService
