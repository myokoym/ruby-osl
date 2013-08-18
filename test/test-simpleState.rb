require "osl"

class SimpleStateTest < Test::Unit::TestCase
  def test_new
    assert_not_nil(Osl::State::SimpleState.new)
  end
end
