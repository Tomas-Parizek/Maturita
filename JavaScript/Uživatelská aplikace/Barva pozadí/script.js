window.onload = setColor(r.value, g.value, b.value);

function setColor(r, g, b)
{
    document.body.style.backgroundColor = `rgb(${r},${g},${b})`

    kod.innerHTML = "#" + byteNaHex(r) + byteNaHex(g) + byteNaHex(b);
}

function byteNaHex(cislo)
{
    let pole = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'];
    let text = "";
    text += pole[parseInt(cislo/16)];
    text += pole[parseInt(cislo%16)];
    return text;
}
