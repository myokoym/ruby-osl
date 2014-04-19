#!/usr/bin/env ruby

require "osl"

state = Osl::State::NumEffectState.new

loop do
  # my turn
  moves = state.generate
  if moves.empty?
    puts "make masita"
    break
  end
  my_move = moves.sample
  state.move(my_move)

  state.show
  puts my_move.to_csa

  if state.in_check?
    puts "checkmate!"
    break
  end

  # your turn
  op_move = nil
  loop do
    line = gets.chomp
    if state.valid_move?(line)
      op_move = line
      break
    end
    puts "Invalid move. Please retry."
  end

  state.move(op_move)

  state.show
  puts op_move
end
