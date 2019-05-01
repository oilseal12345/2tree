import Vue from 'vue'
import App from './App.vue'
import Bootstrap from 'bootstrap/dist/css/bootstrap.min.css'
import firebase from 'firebase'
import VueRouter from 'vue-router'
import Edit from './Edit.vue'
import Home from './home.vue'
Vue.use(VueRouter)

Vue.config.productionTip = false
const routes = [
  {path:'/edit', component:Edit},
  {path:'/', component:Home}
]
const router = new VueRouter({
  routes
})

const config = {
  apiKey: "AIzaSyBiQdPEq4AMKKPe0mxMWVXUh30gcxvbaXs",
  authDomain: "tree-f7129.firebaseapp.com",
  databaseURL: "https://tree-f7129.firebaseio.com",
  projectId: "tree-f7129",
  storageBucket: "tree-f7129.appspot.com",
  messagingSenderId: "160097873361"
};
firebase.initializeApp(config)

new Vue({
  router,
  el:'#app',
  render: h => h(App),  
  Bootstrap
}).$mount('#app')
