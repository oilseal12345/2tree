<template>
  <div :class="['control-card col-12 col-md-4 p-1']">
    <div :class="['row wrapper']">
      <div class="col-4">
        <img class="w-100" :src="image" alt="">
      </div>
      <div class="col-8 center">
        <p>
          {{ name }} = 
          <b>{{ now }}/</b>
          <b>{{ base }}</b>
        </p>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: 'ControlCard',
  props: ['name', 'image', 'now', 'base'],
  computed:{
    makeLowerCase(){
      return this.name.toLowerCase()
    }
  }
}
</script>

<style lang="scss" scoped>
.control-card {
  .wrapper {
    padding: 10px 3px;
    margin: 1px;
  }
  p {
    margin-bottom: 0;
  }
}
.center {
  display: flex;
  justify-content: center;
  align-items: center;
}
.isOff {
  background: #777777!important;
  color: #fff;
}
</style>

