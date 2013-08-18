require "osl"

class SimpleStateTest < Test::Unit::TestCase
  def test_new
    assert_not_nil(Osl::SimpleState.new)
  end
end
