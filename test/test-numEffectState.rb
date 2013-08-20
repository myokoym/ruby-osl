require "osl"

class NumEffectStateTest < Test::Unit::TestCase
  def test_new
    assert_not_nil(Osl::State::NumEffectState.new)
  end

  def test_generate
    nstate = Osl::State::NumEffectState.new
    moves = nstate.generate
    assert_not_nil(moves)
    assert_true(moves.is_a?(Array))
    assert_true(moves.first.is_a?(Osl::Move))
  end

  def test_makeMove
    nstate = Osl::State::NumEffectState.new
    moves = nstate.generate
    assert_nothing_raised do
      nstate.makeMove(moves.first)
    end
    assert_nothing_raised do
      nstate.move(moves.first)  # alias
    end
  end

  def test_inCheck
    nstate = Osl::State::NumEffectState.new
    assert_false(nstate.inCheck)
    assert_false(nstate.in_check?)  # alias
  end
end
