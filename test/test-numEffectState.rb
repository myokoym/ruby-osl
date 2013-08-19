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
end
