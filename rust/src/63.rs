use std::io;
use std::collections::HashSet;
use std::iter::FromIterator;

fn main(){
    let mut s_n = String::new();
    io::stdin().read_line(&mut s_n).ok().expect("read error");
    let n: u32 = s_n.trim().parse().ok().expect("parse error");
    
    let mut vals: Vec<u64> = Vec::new();
    for base in 1..10u64 {
        for power in 1..21u32 {
            let p : u64 = base.pow(power);
            if power == n && p < 10u64.pow(n) && p > 10u64.pow(n-1){
                vals.push(p)
            }
        }
    }
    let h: HashSet<u64> = HashSet::from_iter(vals.iter().cloned());
    let mut ve: Vec<u64> = Vec::from_iter(h.into_iter());
    ve.sort();
    for v in ve {
        println!("{}", v);
    }
}