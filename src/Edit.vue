<template>
   <div id="edit">
    <div>
      <form @submit.prevent="setState">
        <div class="form-row">
          <label for="temperature">Temperature</label>
          <input type="number" class="form-control" id="temperature" v-model="temperature"  placeholder="30">
          <small class="form-text text-muted">ระบุอุณหภูมิที่ต้องการให้ต้นไม้เจริญเติบโต</small>
        </div>
        <div class="form-row">
          <label for="humidity">Humidity</label>
          <input type="number" class="form-control" id="humidity" placeholder="40" v-model="humidity">
          <small class="form-text text-muted">ระบุความชื้นที่ต้องการให้ต้นไม้เจริญเติบโต</small>
        </div>
        <div class="form-row">
          <label for="soilMoisture">Soil moisture</label>
          <input type="number" class="form-control" id="soilMoisture" placeholder="43" v-model="soilMoisture">
          <small class="form-text text-muted">ระบุความชื้นในดินที่ต้องการให้ต้นไม้เจริญเติบโต</small>
        </div>
        <div>
         <button  type="submit" class="btn btn-primary" >ตกลง</button>
        <router-link to="/"><button type="button" class="btn btn-danger">ยกเลิก</button></router-link>
        </div>
      </form>
    </div>     
  </div>
</template>

<script>
import { database } from 'firebase'
export default {
  name: 'edit', 
   data () {
    return { 
    temperature:0,
    humidity:0,
    soilMoisture:0,
    arr:{}
    }
  },
  methods: {
    setState:function(){
      database().ref("temperatureBase").set(this.temperature);
      database().ref("humidityBase").set(this.humidity);
      database().ref("soilMoistureBase").set(this.soilMoisture);
      this.$router.push({path:'/'})
    },
    
  }
}
</script>
<style lang="scss">
  button{
    margin-right: 50px;
  }

</style>
