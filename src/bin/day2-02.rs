fn test(mut nums: Vec<i32>, noun: i32, verb: i32) -> bool {
    nums[1] = noun; nums[2] = verb;

    for ip in (0..nums.len()).step_by(4) {
        let instr = nums[ip];
        let lhs = nums[ip + 1] as usize;
        let rhs = nums[ip + 2] as usize;
        let res = nums[ip + 3] as usize;

        match instr {
            1 => nums[res] = nums[lhs] + nums[rhs],
            2 => nums[res] = nums[lhs] * nums[rhs],
            _ => break 
        }
    }

    *nums.first().unwrap() == 19690720
}
fn main() {
    let input = std::fs::read_to_string("data.txt").unwrap();

    let nums: Vec<i32> = input
    .split(',')
    .map(|x| x.parse::<i32>().unwrap())
    .collect();

    for noun in 0..100 {
        for verb in 0..100 { if test(nums.clone(), noun, verb){ print!("{}", 100 * noun + verb); break; } }
    }
}