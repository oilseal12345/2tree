<template>
  <div id="home">
    <div>
      <div class="row">
        <control-card
        @isClick="triggerState(device)"
        v-for="device in deviceCollection"
        :key="device.name"
        :name="device.name" 
        :now="device.now"
        :base="device.base"
        :image="device.image"/>
      </div>
    </div>
    <div class="row">
      <div class="col-sm-10">  </div>
        <div  class="col-sm-2">
          <router-link to="/edit">
            <button type="button" class="btn btn-info">Edit</button>
          </router-link>
        </div>      
    </div>    
  </div>
</template>

<script>
import { database } from 'firebase'
import ControlCard from '@/components/ControlCard'
export default {
  name: 'home',
  components: {
    ControlCard
  },
  data () {
    return { 
      tembase:0,
      humibase:0,
      soilbase:0,
      deviceCollection: [
        {name: 'Temperature', image: require('./assets/temperature.png'), now: '0', base: 0},
        {name: 'Humidity', image: require('./assets/humidity3.png'), now: '0', base: 0},
        {name: 'Soil moisture', image: require('./assets/soil3.png'), now: '0', base: 0}
      ]
    }
  },
   mounted (){  
    //  console.log(this.deviceCollection[0].base)    
    database().ref("temperatureBase").on('value', (snapshot)=>{
      this.deviceCollection[0].base = snapshot.val()
    })
    database().ref("humidityBase").on('value', (snapshot)=>{
      this.deviceCollection[1].base = snapshot.val()
    })
    database().ref("soilMoistureBase").on('value', (snapshot)=>{
      this.deviceCollection[2].base = snapshot.val()
    })
    database().ref("temperatureNow").on('value', (snapshot)=>{
      this.deviceCollection[0].now = snapshot.val()
    })
    database().ref("humidityNow").on('value', (snapshot)=>{
      this.deviceCollection[1].now = snapshot.val()
    })
    database().ref("soilNow").on('value', (snapshot)=>{
      this.deviceCollection[2].now = snapshot.val()
    })
  },  
  methods: {
    triggerState (device) {
      device.isOn = !device.isOn
      database().ref(device.name).set(device.isOn)
    }
  }
}
</script>
