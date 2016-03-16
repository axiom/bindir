use std::io;
use std::env;

// Parse numbers in decimal, octal, or hexadecimal form and print in all those
// forms.
fn main() {
    let has_args = env::args().len() > 1;

    for argument in env::args().skip(1) {
        do_the_deed(&argument.trim().to_string());
    }

    if has_args {
        return;
    }

    loop {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        input = input.trim().to_string();
        if input == "" {
            break;
        }

        do_the_deed(&input);
    }
}

fn do_the_deed(input: &String) -> () {
    match parse(&input) {
        Some(v) => println!("{} {:#x} {:#o} {:#b}", v, v, v, v),
        None => panic!("Could not parse number."),
    };
}

fn parse(input:&String) -> Option<i64> {
    let digits;
    let radix;

    if input.starts_with("0x") {
        radix = 16;
        digits = input.trim_left_matches("0x").to_string();
    } else if input.starts_with("0o") {
        radix = 8;
        digits = input.trim_left_matches("0o").to_string();
    } else if input.starts_with("0b") {
        radix = 2;
        digits = input.trim_left_matches("0b").to_string();
    } else {
        radix = 10;
        digits = input.to_string();
    }

    i64::from_str_radix(&*digits, radix).ok()
}
