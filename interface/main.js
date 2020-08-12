const native = require('./build/Release/native')

console.log(`JS : ${native.greet('Mathieu')}`)
console.log(`JS : ${native.add(Math.PI, Math.PI)}`)

