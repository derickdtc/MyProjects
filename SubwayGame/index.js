let acc = 0
function increment() {
acc++ ;	
 document.getElementById('count-el').innerText= acc

 
}
function save(){

 document.getElementById('save-el').innerText+=`${acc} --   `;	
 acc=0
 document.getElementById('count-el').innerText= acc;
}