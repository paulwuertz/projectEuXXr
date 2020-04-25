use std::{
    fs::File,
    io::prelude::*
};

fn main(){
    let mut file = File::open("../resources/p059_cipher.txt").unwrap();
    let mut crypt_org = String::new();
    let mut best_org = String::new();
    file.read_to_string(&mut crypt_org);
    println!("{}", crypt_org);
    let mut crypt_num_strings : Vec<&str> = crypt_org.split(",").collect();
    let mut crypt_u8 : Vec<u8> = crypt_num_strings.iter().map(|s| s.parse::<u8>().unwrap()).collect();
    
    let mut found = 0;
    let mut skipped = 0;
    let mut max_score = 0;
    for x in 97..123 { //'a'..'z'
        println!{"x = {}", x};
        for y in 97..123 { //'a'..'z'
          'key_pairs : 
            for z in 97..123 { //'a'..'z'
                let mut crypt = crypt_u8.clone();
                let mut score = 0;
                for (i, c) in crypt.iter_mut().enumerate() {
                    if i%3 == 0      { *c ^= x; }
                    else if i%3 == 1 { *c ^= y; }
                    else if i%3 == 2 { *c ^= z; }
                    //if *c < 32 || *c > 126 {
                    //    skipped += 1;
                    //    break 'key_pairs;
                    //}
                }
                let crypt_ascii = String::from_utf8(crypt).expect("Found invalid UTF-8");
                let lo_crypt = crypt_ascii.to_ascii_lowercase();
                let words = vec![
                    String::from("this"),
                    String::from("that"),
                    String::from("the"),
                ];

                for w in words {
                    if lo_crypt.contains(&w)
                    {
                        let occ_arr : Vec<&str> = lo_crypt.matches(w.as_str()).collect();
                        let occ = occ_arr.len();
                        score += occ;
                        //println!("{} : {}", w, occ);
                    }
                }
                if score >= max_score
                {
                    max_score = score;
                    found+=1;
                    println!("{}", crypt_ascii);
                    println!{"x = {}, y = {}, z = {}, score = {}", x, y, z, score};
                    best_org = crypt_ascii;
                }
            }
        }   
    }
    let mut sum : u32 = 0;
    for c in best_org.as_bytes().iter() {
        sum += *c as u32;
    }
    println!("sum found in {}, skipped: {}, size: {}", sum, skipped, crypt_u8.len());
}