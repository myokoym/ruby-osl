require "osl"

class MoveTest < Test::Unit::TestCase
  def test_new
    assert_not_nil(Osl::Move.new)
  end

  def test_to_csa
    assert_true(Osl::Move.new.to_csa.is_a?(String))
    nstate = Osl::State::NumEffectState.new
    assert_match(/\+[0-9]{4}[A-Z]{2}/, nstate.generate.first.to_csa)
  end
end
