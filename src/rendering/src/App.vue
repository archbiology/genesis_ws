<template>
  <Renderer ref="rendererC" antialias :orbit-ctrl="{ enableDamping: true }" resize="window">
    <Camera :position="{ z: 10 }" />
    <Scene>
      <PointLight :position="{ y: 50, z: 50 }" />
      <Box :size="1" ref="meshC" :rotation="{ y: Math.PI / 4, z: Math.PI / 4 }">
        <LambertMaterial />
      </Box>
    </Scene>
  </Renderer>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import WebSocketClient from './services/webSocketClient';

import { Box, Camera, LambertMaterial, PointLight, Renderer, Scene } from 'troisjs'
const rendererC = ref()
const meshC = ref()
onMounted(() => {
  const renderer = rendererC.value
  const mesh = meshC.value.mesh

  const webSocket = new WebSocketClient();

  webSocket.onConnect(() => {
    console.log('onConnect: Connected to WebSocket server');

    webSocket.sendMsg('Hello, server!');
  });

  webSocket.onMessage((msg) => {
    console.log('onMessage: Received message:', msg);
  });

  webSocket.onClose(() => {
    console.log('onClose: WebSocket connection closed');
  });

  const webSocketUrl = "ws://localhost:7000";
  webSocket.connect(webSocketUrl);

  renderer.onBeforeRender(() => {
    mesh.rotation.x += 0.01
  })
})
</script>

<style>
body {
  margin: 0;
}
canvas {
  display: block;
}
</style>