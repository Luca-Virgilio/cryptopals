

const xor   = (str1, str2) => {
    const bin1 = Buffer.from(str1, 'hex');
    const bin2 =  Buffer.from(str2,'hex');
    
    let res = [];  
    for (let i = 0; i < bin1.length ; i++) {
        res.push(bin1[i] ^ bin2[i]);    
    }

    const stringRes = Buffer.from(res).toString('hex')
    return stringRes;
}


const main = _ =>{
    
    const res = '746865206b696420646f6e277420706c6179';
    const xorRes = xor('1c0111001f010100061a024b53535009181c', '686974207468652062756c6c277320657965');

    (res == xorRes )? console.log('EXERCISE COMPLETED!!!'): console.log('failed');    
}

main();
