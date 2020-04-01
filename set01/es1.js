// es 1 

const hexToBase64 = hexString => {
    const base64String = Buffer.from(hexString, 'hex').toString('base64');
    return base64String;
}

const main = async _ =>{
    const res = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    const hexString = '49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d';

    const base64String = hexToBase64(hexString);
    // console.log("base64", base64String);
    (res == base64String )? console.log('EXERCISE COMPLETED!!!'): console.log('failed');    
}

main();

module.exports = {
    hexToBase64
}