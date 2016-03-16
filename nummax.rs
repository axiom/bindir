use std::io;

fn main() {
	let mut biggest: f64 = 0.0;

	loop {
		let mut input = String::new();

		match io::stdin().read_line(&mut input) {
			Ok(count) => {
				// I think this means we are out of input.
				if count == 0 {
					break;
				}
			},
			Err(e) => {
				println!("err: {}", e);
				break;
			},
		}

		let number: f64 = match input.trim().parse() {
			Ok(x) => x,
			Err(e) => {
				println!("Could not parse number: {}", e);
				continue;
			},
		};

		biggest = number.max(biggest);
	}

	println!("{:.*}", 10, biggest);
}
