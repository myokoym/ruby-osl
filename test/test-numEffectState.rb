require "osl"

class NumEffectStateTest < Test::Unit::TestCase
  def test_new
    assert_not_nil(Osl::State::NumEffectState.new)
  end
end
