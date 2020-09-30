  let display= '';          
  let res = _ => document.getElementById('res').innerHTML = display= _;
document.getElementById('btns').addEventListener('click', e => {
    if (e.target.id === 'btnClr')
    { res(''); }
    else
    if (e.target.id === 'btnEql')
    { res(Math.floor(eval(t.replace(/[01]+/g, '0b$&')) >> 0).toString(2)); }
    else
    { res(display + e.target.innerHTML); }
})