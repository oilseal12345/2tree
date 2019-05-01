<template>
  <div id="app">
   <img src="./assets/final.png" width="250" height="180"/>
    <div class="container">
      <!-- <div class="row">
        <div class="col">
          <hr>
        </div>
      </div> -->
      <router-view></router-view>
    </div>
  </div>     
</template>

<script>
export default {
  name: 'app',
  components: {
  }
}
</script>

<style lang="scss">
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin: 60px 0;
}
</style>
